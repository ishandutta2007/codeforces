#include <iostream>
#include <vector>
using namespace std;
void dfs(int v, vector<vector<int>> &a, vector<int> &used, vector<pair<int, int>> &p)
{
	used[v] = 1;
	for (auto i : a[v])
	{
		if (!used[i])
		{
			p[i].first = v;
			p[i].second = p[v].second + 1;
			dfs(i, a, used, p);
		}
	}
}
int parent(int v, int k, vector<vector<int>> &bp)
{
	for (int i = 20; i >= 0; --i)
	{
		if ((1 << i) <= k)
		{
			v = bp[v][i];
			k -= (1 << i);
		}
	}
	return v;
}
int lca(int a, int b, vector<vector<int>> &bp, vector<pair<int, int>> &p)
{
	if (p[a].second < p[b].second)
	{
		swap(a, b);
	}
	a = parent(a, p[a].second - p[b].second, bp);
	if (a == b)
	{
		return a;
	}
	for (int j = 20; j >= 0; --j)
	{
		if (bp[a][j] != bp[b][j])
		{
			a = bp[a][j];
			b = bp[b][j];
		}
	}
	return p[a].first;
}
int len(int a, int b, vector<vector<int>> &bp, vector<pair<int, int>> &p)
{
	int len1 = p[a].second - p[lca(a, b, bp, p)].second;
	int len2 = p[b].second - p[lca(a, b, bp, p)].second;
	return len1 + len2;
}
bool between(int a, int b, int c, vector<vector<int>> &bp, vector<pair<int, int>> &p) { 
   return len(a, c, bp, p) + len(c, b, bp, p) == len(a, b, bp, p); 
}
int per(int v1, int v2, int u1, int u2, vector<vector<int>> &bp, vector<pair<int, int>> &p)
{
	v2 = lca(v2, u2, bp, p);
	u2 = v2;
	if (between(v1, v2, u1, bp, p) && p[v1].second <= p[v2].second)
	{
			return len(u1, u2, bp, p) + 1;
	}
	/*if (between(v1, v2, u2, bp, p))
	{
		return len(v1, u2, bp, p) + 1;
	}*/
	if (between(u1, u2, v1, bp, p) && p[u1].second <= p[u2].second)
	{
			return len(v1, v2, bp, p) + 1;
	}
	/*	if (between(u1, u2, v2, bp, p))
	{
		return len(u1, v2, bp, p) + 1;
	}*/
	return 0;
}
int res(int a, int b, int c, vector<vector<int>> &bp, vector<pair<int, int>> &p)
{
	int v1 = c, v2 = a, u1 = c, u2 = b;
	if (p[v1].second > p[v2].second)
	{
		swap(v1, v2);
	}
	if (p[u1].second > p[u2].second)
	{
		swap(u1, u2);
	}
	int l1 = lca(v1, v2, bp, p);
	int l2 = lca(u1, u2, bp, p);
	if (l1 == v1)
	{
		if (l2 == u1)
		{
			return per(v1, v2, u1, u2, bp, p);
		}
		else
		{
			int x2 = u1;
			u1 = parent(u2, len(l2, u2, bp, p) - 1, bp);
			int x1 = l2;
			return per(v1, v2, u1, u2, bp, p) + per(v1, v2, x1, x2, bp, p);
		}
	}
	else
	{
		int x1 = l1;
		int x2 = v1;
		v1 = parent(v2, len(l1, v2, bp, p) - 1, bp);
		if (l2 == u1)
		{
			return per(v1, v2, u1, u2, bp, p) + per(x1, x2, u1, u2, bp, p);
		}
		else
		{
			int y2 = u1;
			u1 = parent(u2, len(l2, u2, bp, p) - 1, bp);
			int y1 = l2;
			return per(v1, v2, u1, u2, bp, p) + per(v1, v2, y1, y2, bp, p) + per(x1, x2, u1, u2, bp, p) + per(x1, x2, y1, y2, bp, p);
		}
	}
}
signed main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n);
	for (int i = 1; i < n; ++i)
	{
		int p;
		cin >> p;
		--p;
		a[i].push_back(p);
		a[p].push_back(i);
	}
	vector<pair<int, int>> p(n);
	p[0].first = n;
	p[0].second = 0;
	vector<int> used(n);
	dfs(0, a, used, p);
	vector<vector<int>> bp(n, vector<int>(21));
	for (int j = 0; j <= 20; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (j == 0)
			{
				bp[i][j] = p[i].first;
			}
			else
			{
				if (bp[i][j - 1] == n)
				{
					bp[i][j] = n;
				}
				else
				{
					bp[i][j] = bp[bp[i][j - 1]][j - 1];
				}
			}
		}
	}
	++m;
	while (--m)
	{
		int ans = 1;
		vector<int> now(3);
		cin >> now[0] >> now[1] >> now[2];
		--now[0];
		--now[1];
		--now[2];
		for (int i = 0; i < 3; ++i)
		{
			for (int j = i + 1; j < 3; ++j)
			{
				ans = max(ans, res(now[i], now[j], now[3 - i - j], bp, p));
			}
		}
		cout << ans << "\n";
	}
} /* Fri Dec 13 2019 00:12:12 GMT+0300 (MSK) */