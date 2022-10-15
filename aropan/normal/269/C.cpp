#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 500007;

long long s[MAXN];
int last[MAXN];
int next[MAXN], dest[MAXN], dist[MAXN];
int ans[MAXN];
queue <int> q;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		s[x] += z;
		s[y] += z;
		
		dest[i] = y;
		dist[i] = z;
		next[i] = last[x];
		last[x] = i;
		
		dest[i + m] = x;
		dist[i + m] = z;
		next[i + m] = last[y];
		last[y] = i + m;
	}
	for (int i = 2; i < n; i++)
		s[i] /= 2;
		
	s[1] = 0;
		
	q.push(1);
	while (q.size())
	{
		int x = q.front();
		//cout << x << endl;
		q.pop();
		for (int i = last[x]; i; i = next[i])
		{
			int y = dest[i];
			int z = dist[i];
			//cout << "->" << y << endl;
			if (s[y])
			{
				ans[(i - 1) % m] = i > m;
				//cout << " " << (i - 1) % m << " " << (i > m) << endl;
				if ((s[y] -= z) == 0)
					q.push(y);
			}
		}
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	return 0;
}