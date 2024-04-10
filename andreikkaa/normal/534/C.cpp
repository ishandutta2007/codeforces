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

	long long n, a;
	cin >> n >> a;

	long long d[200000];

	for(int i = 0; i < n; ++i)
		cin >> d[i];

	long long ma = accumulate(d, d + n, 0ll), mi = n;

	for(int i = 0; i < n; ++i)
	{
		int x = max(1ll, a - ma + d[i]);
		int y = min(d[i], a - mi + 1);

		cout << (x - 1) + (d[i] - y) << " ";
	}

	cout << endl;

    return 0;
}