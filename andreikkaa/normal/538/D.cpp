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

bool used[150][150];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	char a[3 * n][3 * n];

	for(int i = 0; i < 3 * n; ++i)
		for(int j = 0; j < 3 * n; ++j)
			a[i][j] = '.';

	for(int i = n; i < n + n; ++i)
	{
		for(int j = n; j < n + n; ++j)
		{
			cin >> a[i][j];
		}
	}

	/*for(int i = 0; i < 3 * n; ++i)
	{
		for(int j = 0; j < 3 * n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/


	vector<pair<int, int>> ans;

	for(int dx = -n + 1; dx < n; ++dx)
	{
		for(int dy = -n + 1; dy < n; ++dy)
		{
			bool st = true, use = false;

			vector<pair<int, int>> was;

			for(int i = n; i < n + n; ++i)
			{
				for(int j = n; j < n + n; ++j)
				{
					if(a[i][j] != 'o')
						continue;

					int cx = i + dx, cy = j + dy;

					if(not(n <= cx and cx < n + n and n <= cy and cy < n + n) or a[cx][cy] == 'o' or used[cx][cy])
						continue;

					if(a[cx][cy] == '.')
					{
						st = false;
						break;
					}

					//cout << cx << " & " << cy << endl;

					was.push_back({cx, cy});

					use = true;
				}

				if(not st)
					break;
			}

			if(st and use)
			{
				ans.push_back({dx, dy});

				for(auto k : was)
					used[k.first][k.second] = true;
			}

		}
	}

	char an[2 * n - 1][2 * n - 1];

	for(int i = 0; i < 2 * n - 1; ++i)
		for(int j = 0; j < 2 * n - 1; ++j)
			an[i][j] = '.';

	an[n - 1][n - 1] = 'o';

	for(auto i : ans)
		an[i.first + n - 1][i.second + n - 1] = 'x';

	for(int i = 0; i < 3 * n; ++i)
		for(int j = 0; j < 3 * n; ++j)
		{
			if(a[i][j] == 'x' and not used[i][j])
			{
				cout << "NO" << endl;
				return 0;
			}
		}

	cout << "YES" << endl;

	for(int i = 0; i < 2 * n - 1; ++i)
	{
		for(int j = 0; j < 2 * n - 1; ++j)
			cout << an[i][j];

		cout << endl;
	}



	return 0;
}