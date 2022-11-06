#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 2e5 + 20;
const int maxb = 21;

vector<int> adj[maxn];

int st[maxn] , ft[maxn] , rst[maxn] , id = -1 , par[maxn][maxb] , x[maxn];
int h[maxn];

void plant(int v)
{
	id++;
	st[v] = id;
	rst[id] = v;
	for(auto u : adj[v])
		if(u != par[v][0])
		{
			h[u] = h[v] + 1;
			par[u][0] = v;
			for(int i = 1; i < maxb; i++)
				par[u][i] = par[par[u][i - 1]][i - 1];
			plant(u);
		}
	ft[v] = id;
}

bool is_par(int v , int u)
{
	return st[v] <= st[u] && st[u] <= ft[v];
}

int go(int v , int h1)
{
	for(int i = 0; i < maxb; i++)
		if(bit(h1 , i))
			v = par[v][i];
	return v;
}

int n;

int mn[maxn * 4] , t[maxn * 4] , Add[maxn * 4];

void build(int s = 0 , int e = n , int v = 1)
{
	t[v] = e - s;
	if(e - s < 2)
		return;

	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
}

void add(int l , int r , int val , int s = 0 , int e = n , int v = 1)
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

	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
	t[v] = 0;

	if(mn[v] == mn[2 * v])
		t[v] += t[2 * v];
	if(mn[v] == mn[2 * v + 1])
		t[v] += t[2 * v + 1];

	mn[v] += Add[v];
}

void handle(int a , int b , int val)
{	
	if(st[a] > st[b])
		swap(a , b);
	if(is_par(a , b))
	{
		add(st[b] , ft[b] + 1 , val);
		b = go(b , h[b] - h[a] - 1);

		add(0 , n , val);
		add(st[b] , ft[b] + 1 , -val);
	}
	else
	{
		add(st[a] , ft[a] + 1 , val);
		add(st[b] , ft[b] + 1 , val);
	}
}

set<pair<int , int>> S;

int main()
{
	int q;
	cin >> n >> q;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	plant(0);
	build();

	for(int i = 0; i < q; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;
		if(a > b)
			swap(a , b);

		if(S.count(make_pair(a , b)))
		{
			handle(a , b , 1);
			S.erase(make_pair(a , b));
		}
		else
		{
			handle(a , b , -1);
			S.insert(make_pair(a , b));
		}

		int ans = t[1];
		if(-mn[1] < (int)S.size())
			ans = 0;

		cout << ans << endl;
	}

}