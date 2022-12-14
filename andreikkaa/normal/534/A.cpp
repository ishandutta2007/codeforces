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

	if(n <= 2)
	{
		cout << 1 << endl << 1 << endl;
	}
	else if(n == 3)
	{
		cout << 2 << endl << "1 3" << endl;
	}
	else
	{
		vector<int> v = {3, 1, 4, 2};

		deque<int> d(v.begin(), v.end());

		for(int i = 5; i <= n; ++i)
		{
			if(i % 2)
				d.push_back(i);
			else
				d.push_front(i);
		}

		cout << n << endl;

		for(auto i : d)
			cout << i << " ";
		cout << endl;
	}

    return 0;
}