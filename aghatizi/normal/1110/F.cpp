#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;

vector<int> adj[maxn] , id , query[maxn];

int st[maxn] , ft[maxn] , w[maxn] , l[maxn] , r[maxn];
ll h[maxn] , mn[maxn * 4] , Add[maxn * 4] , ans[maxn];

void plant(int v)
{
	st[v] = ft[v] = v;
	for(auto u : adj[v])
	{
		h[u] = h[v] + w[u];
		plant(u);
		ft[v] = max(ft[v] , ft[u]);
	}
}

void build(int s = 0 , int e = id.size() , int v = 1)
{
	if(e - s < 2)
	{
		mn[v] = h[id[s]];
		return;
	}

	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
}

void add(int l , int r , int val , int s = 0 , int e = id.size() , int v = 1)
{
	if(l <= s && e <= r)
	{
		Add[v] += val;
		mn[v] += val;
		return;
	}
	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;
	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);

	mn[v] = min(mn[2 * v] , mn[2 * v + 1]) + Add[v];
}

ll get(int l , int r , int s = 0 , int e = id.size() , int v = 1)
{
	if(l <= s && e <= r)
		return mn[v];
	if(r <= s || e <= l)
		return 1e17;

	int m = (s + e) / 2;
	return min(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1)) + Add[v];
}

void dfs(int v)
{
	for(auto ind : query[v])
		ans[ind] = get(l[ind] , r[ind]);

	for(auto u : adj[v])
	{
		int L = lower_bound(id.begin() , id.end() , st[u]) - id.begin();
		int R = upper_bound(id.begin() , id.end() , ft[u]) - id.begin();
		add(L , R , -w[u]);
		add(0 , L , w[u]);
		add(R , id.size() , w[u]);

		dfs(u);

		add(L , R , w[u]);
		add(0 , L , -w[u]);
		add(R , id.size() , -w[u]);
	}
}

int main()
{
	int n , q;
	scanf("%d%d", &n, &q);

	for(int i = 1; i < n; i++)
	{
		int p;
		scanf("%d%d", &p, &w[i]);
		p--;
		adj[p].pb(i);
	}

	for(int i = 1; i < n; i++)
		if(adj[i].empty())
			id.pb(i);

	for(int i = 0; i < q; i++)
	{
		int v;
		scanf("%d%d%d", &v, &l[i], &r[i]);
		l[i]--;
		v--;
		l[i] = lower_bound(id.begin() , id.end() , l[i]) - id.begin();
		r[i] = lower_bound(id.begin() , id.end() , r[i]) - id.begin();

		query[v].pb(i);
	}

	plant(0);
	build();
	dfs(0);

	for(int i = 0; i < q; i++)
		printf("%lld\n", ans[i]);
}