#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200000;

int n, m, w[maxn], c[maxn], par[maxn], sz[maxn], ee[maxn], u[maxn], v[maxn], s, tin[maxn], tout[maxn], tik_tak, best = -1, eout, ein, dans = 1, up[200000][19];
ll ans;
bool in[maxn];
vector<pair<int,int>> g[maxn];
pair<int,int> st[200000][19];

int find(int v)
{
	if(v != par[v]) par[v] = find(par[v]);
	return par[v];
}

void unite(int u, int v)
{
	u = find(u);
	v = find(v);
	if(sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v];
	par[v] = u;
}

void dfs(int v, int p)
{
	tin[v] = tik_tak++;
	for(int i = 1; i < 19; i++)
	{
		up[v][i] = up[up[v][i - 1]][i - 1];
		st[v][i] = max(st[v][i - 1], st[up[v][i - 1]][i - 1]);
	}
	for(pair<int,int> edge : g[v])
	{
		int to = edge.first, e1 = edge.second;
		if(to == p) continue;
		st[to][0] = {w[e1], e1};
		up[to][0] = v;
		dfs(to, v);
	}
	tout[v] = tik_tak++;
}

bool upper(int u, int v)
{
	return tin[u] < tin[v] && tout[u] > tout[v];
}

void update(int u1, int v1, int w1, int c1, int idx)
{
	if(tin[u1] > tin[v1]) swap(u1, v1);
	pair<int,int> res = {-1, -1};
	if(upper(u1, v1))
	{
		for(int i = 18; i >= 0; i--)
		{
			if(upper(up[v1][i], u1)) continue;
			res = max(res, st[v1][i]);
			v1 = up[v1][i];
		}
	}
	else
	{
		for(int i = 18; i >= 0; i--)
			{
				if(upper(up[v1][i], u1)) continue;
				res = max(res, st[v1][i]);
				v1 = up[v1][i];
			}
		for(int i = 18; i >= 0; i--)
			{
				if(upper(up[u1][i], v1)) continue;
				res = max(res, st[u1][i]);
				u1 = up[u1][i];
			}
		res = max({res, st[u1][0], st[v1][0]});
	}
	int cur_d = -res.first + w1 - s / c1;
	if(cur_d < dans)
	{
		dans = cur_d;
		ein = idx;
		eout = res.second;
	}
}

int main()
{

	// READ
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> w[i];
	for(int i = 0; i < m; i++) cin >> c[i];
	for(int i = 0; i < m; i++) cin >> u[i] >> v[i], --u[i], --v[i];
	cin >> s;
	// READ


	// KRUSKAL
	for(int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
	for(int i = 0; i < m; i++) ee[i] = i;
	sort(ee, ee + m, [](int e1, int e2){return w[e1] < w[e2];});
	for(int i = 0; i < m; i++)
	{
		int e1 = ee[i], u1 = u[e1], v1 = v[e1];
		if(find(u1) == find(v1)) continue;
		unite(u1, v1);
		ans += w[e1];
		in[e1] = true;
		g[u1].push_back({v1, e1});
		g[v1].push_back({u1, e1});
	}
	// KRUSKAL


	// CALC
	dfs(0, -1);
	for(int i = 0; i < m; i++)
	{
		if(in[i])
		{
			if(best == -1 || c[best] > c[i]) best = i;
			continue;
		}
		update(u[i], v[i], w[i], c[i], i);
	}
	if(dans < -(s / c[best]))
	{
		ans += dans;
		in[eout] = false;
		in[ein] = true;
		w[ein] -= s / c[ein];
	}
	else
	{
		w[best] -= s / c[best];
		ans -= s / c[best];
	}
	// CALC


	// WRITE
	cout << ans << endl;
	for(int i = 0; i < m; i++)
		if(in[i]) cout << i + 1 << ' ' << w[i] << endl;
	// WRITE

}