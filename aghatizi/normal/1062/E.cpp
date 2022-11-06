#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxb = 20;

struct node
{
	array<int , 2> mx , mn;
	node()
	{
		mx.fill(maxn - 10);
		mn.fill(maxn - 1);
	}
};

node seg[maxn * 4] , void_node;

vector<int> adj[maxn];

int st[maxn] , ft[maxn] , now = -1 , par[maxn][maxb] , h[maxn];

int n;

inline bool cmp(int x , int y)
{
	return st[x] < st[y];
}

inline void plant(int v)
{
	st[v] = ++now;

	for(auto u : adj[v])
	{
		par[u][0] = v;
		for(int i = 1; i < maxb; i++)
			par[u][i] = par[par[u][i - 1]][i - 1];

		h[u] = h[v] + 1;
		plant(u);
	}

	ft[v] = now;
}

node merge(node a , node b)
{
	node c;

	vector<int> tmpmn , tmpmx;

	for(int i = 0; i < 2; i++)
	{
		tmpmn.pb(a.mn[i]);
		tmpmx.pb(a.mx[i]);
		tmpmn.pb(b.mn[i]);
		tmpmx.pb(b.mx[i]);
	}

	sort(tmpmn.begin() , tmpmn.end() , cmp);
	sort(tmpmx.begin() , tmpmx.end() , cmp);

	reverse(tmpmx.begin() , tmpmx.end());
	for(int i = 0; i < 2; i++)
		tmpmn.pop_back() , tmpmx.pop_back();
	reverse(tmpmx.begin() , tmpmx.end());

	for(int i = 0; i < 2; i++)
		c.mx[i] = tmpmx[i] , c.mn[i] = tmpmn[i];

	return c;
}

inline void build(int s = 0 , int e = n , int v = 1)
{
	if(e - s < 2)
	{
		seg[v].mx[1] = s;
		seg[v].mn[0] = s;
		return;
	}
	
	int m = (s + e) / 2;

	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

node get(int l , int r , int s = 0 , int e = n , int v = 1)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return void_node;

	int m = (s + e) / 2;

	return merge(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

inline bool is_par(int v , int u)
{
	return st[v] <= st[u] && st[u] <= ft[v];
}

inline int lca(int v , int u)
{
	for(int i = maxb - 1; i >= 0; i--)
		if(!is_par(par[v][i] , u))
			v = par[v][i];

	if(is_par(v , u))
		return v;
	else
		return par[v][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	st[maxn - 1] = 1e9;

	int q;
	cin >> n >> q;

	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p;
		p--;

		adj[p].pb(i);
	}

	plant(0);
	build();

	while(q--)
	{
		int l , r;
		cin >> l >> r;
		l--;

		if(r - l == 2)
		{
			r--;
			if(h[l] > h[r])
				cout << r + 1 << " " << h[l] << endl;
			else
				cout << l + 1 << " " << h[r] << endl;
			
			continue;
		}

		node tmp = get(l , r);

		int x = h[lca(tmp.mn[1] , tmp.mx[1])] , y = h[lca(tmp.mn[0] , tmp.mx[0])];

		if(x > y)
			cout << tmp.mn[0] + 1 << " ";
		else
			cout << tmp.mx[1] + 1 << " ";

		cout << max(x , y) << endl;
	}
}