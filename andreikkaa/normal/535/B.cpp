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

	string n;
	cin >> n;

	int m = 0;

	for(auto i : n)
	{
		m <<= 1;

		if(i == '7')
		{
			m |= 1;
		}
	}

	int c = 1;
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < (1 << (i + 1)); ++j, ++c)
		{
			if(j == m and i + 1 == n.size())
			{
				cout << c << endl;
				return 0;
			}
		}
	}


    return 0;
}