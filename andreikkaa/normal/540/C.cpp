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

bool a[502][502];
bool used[502][502];
queue<pair<int, int>> q;

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			char c;
			cin >> c;

			if(c == '.')
				a[i][j] = true;
		}
	}

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	q.push({x1, y1});
	used[x1][y1] = true;

	const int dx[] = {-1, 0, 1, 0};
	const int dy[] = {0, 1, 0, -1};

	bool st = false;

	while(not q.empty())
	{
		int x = q.front().first, y = q.front().second;

		q.pop();

		a[x][y] = false;

		for(int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i], ny = y + dy[i];

			if(nx == x2 and ny == y2)
			{
				st = true;
				break;
			}

			if(a[nx][ny] and not used[nx][ny])
			{
				used[nx][ny] = true;
				q.push({nx, ny});
			}
		}

		if(st)
			break;
	}

	if(not st)
	{
		cout << "NO" << endl;
		return 0;
	}
	else if(not a[x2][y2])
	{
		cout << "YES" << endl;
		return 0;
	}

	for(int i = 0; i < 4; ++i)
	{
		int nx = x2 + dx[i], ny = y2 + dy[i];

		if(a[nx][ny])
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}