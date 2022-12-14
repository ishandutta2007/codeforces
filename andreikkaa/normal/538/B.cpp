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

	int n;
	cin >> n;

	int a[7];

	for(int i = 0; i < 7; ++i)
	{
		a[i] = n % 10;
		n /= 10;
	}

	vector<int> ans;

	bool st = true;

	while(st)
	{
		int cur = 0;
		st = false;

		for(int i = 6; i >= 0; --i)
		{
			cur *= 10;

			if(a[i] > 0)
			{
				++cur;
				--a[i];
				st = true;
			}
		}

		if(cur > 0)
			ans.push_back(cur);
	}

	cout << ans.size() << endl;

	for(int i : ans)
		cout << i << " ";





	return 0;
}