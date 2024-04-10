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

long long dp[501][501];

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);

	dp[0][0] = 1;

	long long n, m, b, v;
	cin >> n >> m >> b >> v;

	int a[501];

	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			for(int k = 0; k <= b; ++k)
			{
				if(k + a[i] <= b)
				{
					dp[j + 1][k + a[i]] += dp[j][k];
					dp[j + 1][k + a[i]] %= v;
				}
			}
		}
	}

	long long sum = 0;

	for(int i = 0; i <= b; ++i)
		sum += dp[m][i];

	cout << sum % v << endl;


    return 0;
}