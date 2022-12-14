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

pair<int, int> a[1000];
int n;

long long f(int x)
{
	long long w = 0;
	for(int i = 0; i < n; ++i)
	{
		if(a[i].second <= x)
		{
			w += a[i].first;
		}
		else if(a[i].first <= x)
		{
			w += a[i].second;
		}
		else
		{
			return 1000000000000000;
		}
	}
	return w * x;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i].first >> a[i].second;
		if(a[i].first > a[i].second)
			swap(a[i].first, a[i].second);
	}



	long long ans = 1000000000000000;
	for(int i = 1000; i >= 0; --i)
	{
		//cout << i << " " << f(i) << endl;
		ans = min(ans, f(i));
	}

	cout << ans << endl;

    return 0;
}