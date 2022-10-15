#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 107;

int a[MAXN][MAXN];
int f[MAXN];
int n, m;

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d %d", &n, &m);
	
	
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		s += k;
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			a[i][x] = true;
		}
	}
	
	if (s == 0)
	{
		printf("%d\n", n);
		return 0;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (!f[i])
		{
			queue <int> q;
			q.push(i);
			f[i] = true;
			while (q.size())
			{
				int x = q.front();
				q.pop();
				for (int j = 1; j <= n; j++)
					if (!f[j])
						for (int k = 1; k <= m; k++)
							if (a[x][k] && a[j][k])
							{
								q.push(j);
								f[j] = true;
								break;
							}
			}
			ans++;
		}
	printf("%d\n", ans - 1);
	return 0;
}