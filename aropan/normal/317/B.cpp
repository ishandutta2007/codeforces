#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <queue>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 500;

int n, m;
queue < pair <int, int> > q;
int u[MAXN + MAXN + 7][MAXN + MAXN + 7];
int a[MAXN + MAXN + 7][MAXN + MAXN + 7];

int main()
{
	#ifdef MJUDGE
		assert(freopen("in", "r", stdin));
		assert(freopen("out", "w", stdout));
	#endif
	
	scanf("%d %d", &n, &m);
	a[MAXN][MAXN] = n;
	if (n > 3)
		q.push(make_pair(MAXN, MAXN));
	while (q.size())
	{
		int
			x = q.front().first,
			y = q.front().second;
		q.pop();
		u[x][y] = false;

		int v = a[x][y] / 4;
		a[x][y] -= v * 4;
		
		if (a[x][y] >= 4 && !u[x][y])
		{
			u[x][y] = true;
			q.push(make_pair(x, y));
		}
		for (int dx = -1; dx <= 1; dx += 1)
			for (int dy = dx? 0 : -1; dy <= 1; dy += 2)
			{
				x += dx;
				y += dy;
				a[x][y] += v;
				if (a[x][y] >= 4 && !u[x][y])
				{
					u[x][y] = true;
					q.push(make_pair(x, y));
				}
				x -= dx;
				y -= dy;
			}
	}

	while (m--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x += MAXN;
		y += MAXN;
		printf("%d\n", x < 0 || MAXN + MAXN <= x || y < 0 || MAXN + MAXN <= y? 0 : a[x][y]);
		//printf("%d %d\n", rand() % 100 - 50, rand() % 100 - 50);
	}
	
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}