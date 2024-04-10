#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

const int MAXN = 200007;
const int MAXM = 400007;
const long long INF = (long long)1e+18;

int last[MAXN], dest[MAXM], dist[MAXM], next[MAXM];
bool f[MAXN];
int p[MAXN];
long long d[MAXN];
int n, m;
priority_queue < pair <long long, int> > h;
vector < pair < long long, pair <int, int> > > a;
int root[MAXN];

int FIND(int x)
{
	if (root[x] != x) root[x] = FIND(root[x]);
	return root[x];
}

bool UNION(int x, int y)
{
	x = FIND(x);
	y = FIND(y);
	if (x == y) return false;

	if (rand() & 1)
		swap(x, y);

	root[x] = y;
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen(".in", "r", stdin);
		freopen(".out", "w", stdout);
	#endif
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, d;
		scanf("%d %d %d", &x, &y, &d);


		dest[i] = y;
		dist[i] = d;
		next[i] = last[x];
		last[x] = i;

		dest[i + m] = x;
		dist[i + m] = d;
		next[i + m] = last[y];
		last[y] = i + m;
	}


	for (int i = 1; i <= n; i++)
		d[i] = INF;

	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int x;
		scanf("%d", &x);
		f[x] = true;
		p[x] = x;
		d[x] = 0;
		h.push(make_pair(0LL, x));
	}

	while (h.size())
	{
		int x = h.top().second;
		long long l = -h.top().first;
		h.pop();
		if (l != d[x]) continue;

		for (int i = last[x]; i; i = next[i])
		{
			int y = dest[i];
			l += dist[i];
			if (l < d[y])
			{
				p[y] = p[x];
				d[y] = l;
				h.push(make_pair(-d[y], y));
			}
			l -= dist[i];
		}
	}
	for (int x = 1; x <= n; x++)
		for (int i = last[x]; i; i = next[i])
			a.push_back(make_pair(d[x] + d[dest[i]] + dist[i], make_pair(p[x], p[dest[i]])));

	sort(a.begin(), a.end());

	long long ans = d[1];
	for (int i = 1; i <= n; i++)
		root[i] = i;

	for (int i = 0; i < (int)a.size(); i++)
		if (UNION(a[i].second.first, a[i].second.second))
			ans += a[i].first;
	cout << ans << endl;
	return 0;	
}