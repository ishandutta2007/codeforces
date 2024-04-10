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

long double dp[101][101][101];

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);

	int a, b, c;
	cin >> a >> b >> c;

	dp[a][b][c] = 1;

	cout.precision(15);

	for(int x = a; x >= 0; --x)
	{
		for(int y = b; y >= 0; --y)
		{
			for(int z = c; z >= 0; --z)
			{
				int cnt = 0;
				cnt += x == 0;
				cnt += y == 0;
				cnt += z == 0;

				if(cnt >= 2)
					continue;

				long double apr = x * y / (long double)(x * y + y * z + z * x);
				long double bpr = y * z / (long double)(x * y + y * z + z * x);
				long double cpr = x * z / (long double)(x * y + y * z + z * x);

				if(y != 0)
					dp[x][y - 1][z] += dp[x][y][z] * apr;

				if(z != 0)
					dp[x][y][z - 1] += dp[x][y][z] * bpr;

				if(x != 0)
					dp[x - 1][y][z] += dp[x][y][z] * cpr;
			}
		}
	}

	long double apr = 0;

	for(int i = 1; i <= a; ++i)
	{
		apr += dp[i][0][0];
	}

	long double bpr = 0;

	for(int i = 1; i <= b; ++i)
	{
		bpr += dp[0][i][0];
	}

	long double cpr = 0;

	for(int i = 1; i <= c; ++i)
	{
		cpr += dp[0][0][i];
	}


	cout.precision(15);
	cout << apr << " " << bpr << " " << cpr << endl;

	return 0;
}