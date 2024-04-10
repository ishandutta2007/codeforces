/**
	inline void prlong long_hello()
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
#include <numeric>
#include <regex>
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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> m >> n;

	pair<int, int> a[n];

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i].first >> a[i].second;
	}

	int best = a[0].second + a[0].first - 1;

	for(int i = 0; i < n - 1; ++i)
	{
		if(abs(a[i].first - a[i + 1].first) < abs(a[i].second - a[i + 1].second))
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}

		int x1 = a[i].first, x2 = a[i + 1].first, y1 = a[i].second, y2 = a[i + 1].second;

		best = max(best, (y1 + y2 + x2 - x1) / 2);
	}

	best = max(best, a[n - 1].second + m - a[n - 1].first);

	cout << best << endl;


	return 0;
}