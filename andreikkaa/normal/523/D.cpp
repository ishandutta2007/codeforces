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

class cmp
{
public:
	bool operator()(const long long& a, const long long& b)
	{
		return a > b;
	}
};

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	priority_queue<long long, vector<long long>, cmp> q;

	for(int i = 0; i < k; ++i)
		q.push(0ll);

	for(int i = 0; i < n; ++i)
	{
		int _s, _m;
		scanf("%d %d", &_s, &_m);

		long long s = _s, m = _m;

		long long best = q.top();
		q.pop();

		long long finish;

		if(best >= s)
		{
			finish = best + m;
		}
		else
		{
			finish = s + m;
		}

		printf("%I64d\n", finish);

		q.push(finish);
	}
    return 0;
}