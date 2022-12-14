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

long long c, hr, hb, wr, wb;

inline long long g(int a)
{
	if(a < 0)
		return -1;

	if(c - a * wr < 0)
		return -1;

	int b = (c - a * wr) / wb;

	return a * hr + b * hb;
}

inline long long f(int l, int r)
{
	while(r - l > 2)
	{
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;

		if(g(m1) < g(m2))
			l = m1;
		else
			r = m2;
	}

	return max(max(g(l), g(l + 1)), g(l + 2));
}

inline long long solve()
{
	long long maxr = c / wr;
	long long step = max(1ll, maxr / 10);

	long long ans = 0;

	for(long long i = 0; i <= maxr; i += step)
	{
		ans = max(ans, f(i, i + step));
	}

	for(long long i = -(rand() % step); i <= maxr; i += step)
	{
		ans = max(ans, f(i, i + step));
	}

	for(long long i = (rand() % step); i <= maxr; i += step)
	{
		ans = max(ans, f(i, i + step));
	}

	return ans;
}

int main()
{
	srand(1303);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> c >> hr >> hb >> wr >> wb;


	long long ans = solve();
	int c = 0;

	while(clock() / (long double) CLOCKS_PER_SEC < 0.5)
	{
		swap(hr, hb);
		swap(wr, wb);

		ans = max(ans, solve());

		if(++c == 10000)
			break;
	}


	cout << ans << endl;

    return 0;
}