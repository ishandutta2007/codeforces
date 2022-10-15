#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;


const int MAXN = 100007;

int n, k;
char a[2][MAXN];
int f[2][MAXN];
queue < pair <int, int> > q;
int l;

bool add(int x, int y, int l)
{
	if (y > n) return true;
	if (y <= l - 1 || a[x][y] == 'X' || f[x][y]) return false;
	f[x][y] = l;
	q.push(make_pair(x, y));
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < 2; i++)
		scanf("%s", a[i] + 1);
	add(0, 1, 1);
	while (q.size())
	{
		int
			x = q.front().first,
			y = q.front().second;
		int
			l = f[x][y] + 1;
		q.pop();
			
		if (
			add(x, y + 1, l) ||
			add(x, y - 1, l) ||
			add(1 - x, y + k, l)
		)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}