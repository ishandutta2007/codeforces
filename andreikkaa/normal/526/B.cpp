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

// ===== IO, STRINGS SECTION =====

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

// ===== STL SECTION =====

#include <algorithm>
#include <array>
#include <list>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// ===== OTHER LIBS SECTION =====

#include <math.h>
#include <stdlib.h> // RANDOM IS MY HOME!!!
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <memory.h>

/* _____ SPECIAL FEATURES _____ */

using namespace std;

/* _____ CODE _____ */

int a[10000];
int dp[10000];

int f(int x)
{
	if(x == 1)
		return 0;
	return f(x / 2) + a[x];
}

int n;

void g(int x)
{
	if(x >= (1 << n))
	{
		return;
	}
	else
	{
		g(2 * x);
		g(2 * x + 1);

		int minn = min(dp[2 * x], dp[2 * x + 1]);

		dp[x] = minn;

		dp[2 * x] -= minn;
		dp[2 * x + 1] -= minn;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	cin >> n;



	for(int i = 2; i < (1 << (n + 1)); ++i)
	{
		cin >> a[i];
	}

	int maxx = -1;
	for(int i = (1 << n); i < (1 << (n + 1)); ++i)
	{
		maxx = max(f(i), maxx);
	}

	for(int i = (1 << n); i < (1 << (n + 1)); ++i)
	{
		dp[i] = maxx - f(i);
	}

	g(1);

	int ans = 0;

	for(int i = 0; i < (1 << (n + 1)); ++i)
	{
		ans += dp[i];
	}

	cout << ans << endl;

    return 0;
}