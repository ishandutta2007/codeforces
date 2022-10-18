#include <bits/stdc++.h>

using namespace std;

struct point
{
	int x;
	int64_t y;
	point operator -(point b)
	{
		point r;
		r.x = x - b.x;
		r.y = y - b.y;
		return r;
	}
};

int64_t cross(point a, point b)
{
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

const int maxn = 1e5 + 42;

vector<int> g[maxn];
int in[maxn], out[maxn];
int t;
void dfs(int v)
{
	in[v] = ++t;
	for(auto u: g[v])
		dfs(u);
	out[v] = ++t;
}

bool is_par(int a, int b)
{
	return in[a] <= in[b] && out[b] <= out[a];
}

signed main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	point r[n];
	for(int i = 0; i < n; i++)
	{
		int a;
		int64_t b;
		cin >> a >> b;
		r[i].x = a;
		r[i].y = b;
	}
	if(n == 1)
	{
		int m;
		cin >> m;
		while(m--)
			cout << 1 << ' ';
		return 0;
	}
	vector<int> hull{n - 1, n - 2};
	const int logn = 21;
	int up[n][logn];
	for(int i = 0; i < n; i++)
		fill(up[i], up[i] + logn, n - 1);
	for(int i = n - 3; i >= 0; i--)
	{
		while(hull.size() >= 2 && cross(r[i] - r[hull[hull.size() - 2]], r[hull[hull.size() - 1]] - r[hull[hull.size() - 2]]) > 0)
			hull.pop_back();
		up[i][0] = hull.back();
		for(int j = 1; j < logn; j++)
			up[i][j] = up[up[i][j - 1]][j - 1];
		hull.push_back(i);
	}
	for(int i = 0; i < n - 1; i++)
		g[up[i][0]].push_back(i);
	dfs(n - 1);
	int m;
	cin >> m;
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		for(int i = logn - 1; i >= 0; i--)
			if(!is_par(up[a][i], b))
				a = up[a][i];
		if(!is_par(a, b))
			a = up[a][0];
		cout << a + 1 << " ";
	}
}