/**
	inline void print_hello()
	{
		string message = R"(Hello!

		My name is Andrey E. Kalendarov,
		And I'm waiting for OK (or AC) status.

		Yes, please, don't blame my code.
		I know that it's far from ideal.
		But it should pass all the tests.

		And everybody will be happy.
		And you, my dear reader, too.
		I'm sure.

		Goodbye.)";

		cout << message << endl;
	}
**/

/* _____ INCLUDES _____ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* _____ CODE _____ */

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	string big[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	string small[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string medium[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

	if(n < 20)
	{
		if(n == 0)
			cout << "zero" << endl;
		else if(n < 10)
		{
			cout << small[n] << endl;
		}
		else
		{
			cout << medium[n - 10] << endl;
		}
	}
	else
	{
		if(n % 10 != 0)
			cout << big[n / 10] << "-" << small[n % 10] << endl;
		else
			cout << big[n / 10] << endl;
	}

    return 0;
}