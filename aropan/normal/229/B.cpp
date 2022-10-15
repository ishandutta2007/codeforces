#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 200007;
const int MAXM = 400007;
const int INF = (int)2e+9 + 7;

int last[MAXN];
int dest[MAXM], dist[MAXM], next[MAXM];
int state[MAXN], f[MAXN];
priority_queue < pair <int, int> > H;
int n, m;
set < int > S[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		
		dest[i] = y;
		dist[i] = z;
		next[i] = last[x];
		last[x] = i;
		
		dest[i + m] = x;
		dist[i + m] = z;
		next[i + m] = last[y];
		last[y] = i + m;
	}
	
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
		{
			int x;
			scanf("%d", &x);
			S[i].insert(x);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = INF;
		state[i] = 0;
	}
	
	f[1] = 0;
	H.push(make_pair(0, 1));
	while (H.size())
	{
		int
			x = H.top().second,
			l = -H.top().first;
		H.pop();
		
		if (state[x] == 2) continue;
		if (f[x] != l) continue;
		
		if (state[x] == 0)
		{
			if (x == n)
			{
				printf("%d\n", l);
				return 0;
			}
			while (S[x].find(l) != S[x].end()) l++;
			f[x] = l;
			H.push(make_pair(-l, x));
			state[x] = 1;
			continue;
		}
		state[x] = 2;
		
		for (int i = last[x]; i; i = next[i])
		{
			int y = dest[i];
			l += dist[i];
			if (state[y] == 0 && l < f[y])
			{
				f[y] = l;
				H.push(make_pair(-l, y));
			}
			l -= dist[i];
		}
	}
	puts("-1");
	return 0;
}