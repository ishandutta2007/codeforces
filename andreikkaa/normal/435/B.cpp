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

	string s;
	int k;

	cin >> s >> k;

	for(unsigned i = 0; i < s.size(); ++i)
	{
		char cm = s[i], cp = i;

		for(unsigned j = i; j <= min(i + k, (unsigned) s.size() - 1); ++j)
		{
			if(s[j] > cm)
			{
				cm = s[j];
				cp = j;
			}
		}

		for(unsigned j = cp; j > i; --j)
		{
			swap(s[j], s[j - 1]);
		}

		k -= cp - i;
	}

	cout << s << endl;

    return 0;
}