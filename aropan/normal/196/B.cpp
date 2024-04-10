#include <cstdio>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 2000;
const int INF = (int)1e+9;
const pair <int, int> z = make_pair(INF, INF);

queue < pair < pair <int, int>, pair <int, int> > > q;
char a[MAXN][MAXN];
pair <int, int> f[MAXN][MAXN];
int n, m;

void add(int x, int y, int i, int j)
{
	if (x < 0)
	{
		x += n;
		i--;
	}
	if (x >= n)
	{
		x -= n;
		i++;
	}
	if (y < 0)
	{
		y += m;
		j--;
	}
	if (y >= m)
	{
		y -= m;
		j++;
	}
	if (a[x][y] == '#') return;

	if (f[x][y] != z)
	{
		if (f[x][y] != make_pair(i, j))
		{
			puts("Yes");
			exit(0);
		}
		return;
	}
	f[x][y] = make_pair(i, j);
	q.push(make_pair(make_pair(x, y), make_pair(i, j)));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen(".in", "r", stdin);
		freopen(".out", "w", stdout);
	#endif

	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++)
		gets(a[i]);

	int x, y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 'S')
			{
				x = i;
				y = j;
			}
			f[i][j] = z;
		}

	a[x][y] = '.';
	add(x, y, 0, 0);
	while (q.size())
	{
		int
			x = q.front().first.first,
			y = q.front().first.second,
			i = q.front().second.first,
			j = q.front().second.second;
		q.pop();
		add(x + 1, y, i, j);
		add(x - 1, y, i, j);
		add(x, y + 1, i, j);
		add(x, y - 1, i, j);

	}
	puts("No");
	return 0;	
}