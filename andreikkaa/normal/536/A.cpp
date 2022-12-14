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

long long a, b, n;
int l, t, m;

bool f(int l, int r)
{
	//cout << l << " & " << r << endl;

	int bite = min(r - l + 1, m);

	long long len = (r - l + 1);

	long long sum = len * a + (len * (len + 1) / 2 + len * (l - 2)) * b;

	//cout << len << ", " << sum << ", " << bite << endl;

	//cout << (((sum + bite) / bite) <= t) << endl;

	return (long long)(ceil(sum / (long double)(bite))) <= t and a + b * (r - 1) <= t;
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	cin >> a >> b >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> l >> t >> m;

		int L = l, R = L + 2e7;

		while(L != R)
		{
			int M = (L + R) / 2;

			if(f(l, M))
				L = M + 1;
			else
				R = M;
		}


		if(f(l, L))
		{
			if(L < l)
				cout << -1 << endl;
			else
				cout << L << endl;
		}
		else
		{
			if(L - 1 < l)
				cout << -1 << endl;
			else
				cout << L - 1 << endl;
		}


	}





    return 0;
}