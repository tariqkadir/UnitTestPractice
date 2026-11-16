/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_repeated_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("@@@@@@@@@@91302q");
	ASSERT_EQ(10, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, lower_and_uppercase_repeated_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZzZzZzZz");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, repeated_letters_mid_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("asdfZZZZw62d");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, repeated_letters_end_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("wehcyaZZZ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, no_mixed_case_all_chars)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("12133@3adasfcdcvsfdfc221");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, has_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AaAaByewewc");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_empty_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("124543982319419372183");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_special_chars)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("!@#$%^*($*@&%!%^#)");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_lowercase_chars)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("password");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_uppercase_chars)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("PASSWORD");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, has_mixed_case_all_chars)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Password123$%^");
	ASSERT_EQ(true, actual);
}