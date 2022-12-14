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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int m, k;
	cin >> m >> k;

	map<int, set<int>> s;

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		s[a].insert(b);
		s[b].insert(a);
	}

	if(k == 0)
	{
		for(auto i : s)
		{
			cout << i.first << ": ";
			vector<int> ans;
			for(auto j : s)
			{
				if(i.second.find(j.first) == i.second.end() and j.first != i.first)
				{
					ans.push_back(j.first);
				}
			}
			cout << ans.size() << " ";
			for(auto i : ans)
				cout << i << " ";
			cout << endl;
		}
		return 0;
	}

	for(auto i : s)
	{
		map<int, int> cur;
		for(auto j : i.second)
		{
			for(auto k : s[j])
			{
				++cur[k];
			}
		}
		cout << i.first << ": ";
		vector<int> ans;
		for(auto j : cur)
		{
			if(j.second * 100 >= k * i.second.size() and j.first != i.first and i.second.find(j.first) == i.second.end())
			{
				ans.push_back(j.first);
			}
		}
		cout << ans.size() << " ";
		for(auto i : ans)
			cout << i << " ";
		cout << endl;
	}

    return 0;
}