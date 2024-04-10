#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int maxb = 20;

struct node
{
	int a , b;
	bool bad;

	node()
	{
		a = b = -1;
		bad = 0;
	}
};

vector<int> adj[maxn];

node seg[maxn * 4] , void_node;

int n , arr[maxn * 2] , mn[maxb][maxn * 2] , h[maxn] , id , p[maxn];
int st[maxn] , hb[maxn * 2] , ft[maxn] , rst[maxn * 2];

void dfs(int v)
{
	st[v] = id;
	rst[id] = v;
	arr[id++] = st[v];
	for(auto u : adj[v])
	{
		h[u] = h[v] + 1;
		dfs(u);
		arr[id++] = st[v];
	}
	ft[v] = id;
}

inline int lca(int v , int u)
{
	v = st[v] , u = st[u];

	if(v > u)
		swap(v , u);

	int id = hb[u - v + 1];
	return rst[min(mn[id][v] , mn[id][u - (1 << id) + 1])];
}

inline int dist(int v , int u)
{
	return h[v] + h[u] - 2 * h[lca(v , u)];
}

node merge(node a , node b)
{
	if(a.a == -1)
		return b;
	if(b.a == -1)
		return a;

	node c;
	c.bad = a.bad | b.bad;
	c.a = 0;

	if(c.bad)
		return c;

	vector<int> tmp = {a.a , a.b , b.a , b.b};
	for(int i = 0; i < 4; i++)
		for(int j = i + 1; j < 4; j++)
		{
			bool f = 1;

			int len = dist(tmp[i] , tmp[j]);
			for(int k = 0; k < 4; k++)
				if(k != i && k != j && len != dist(tmp[i] , tmp[k]) + dist(tmp[k] , tmp[j]))
				{
					f = 0;
					break;
				}

			if(f)
			{
				c.a = tmp[i];
				c.b = tmp[j];
				return c;
			}
		}

	c.bad = 1;
	return c;
}

void Set(int p , int val , int s = 0 , int e = n , int v = 1)
{
	if(e - s < 2)
	{
		seg[v].a = seg[v].b = val;
		seg[v].bad = 0;
		return;
	}
	
	int m = (s + e) / 2;
	if(p < m)
		Set(p , val , s , m , 2 * v);
	else
		Set(p , val , m , e , 2 * v + 1);

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

int GetAns(node x , int s = 0 , int e = n , int v = 1)
{
	if(e - s < 2)
	{
		if(merge(x , seg[v]).bad)
			return -1;
		else
			return s + 1;
	}

	int m = (s + e) / 2;

	if(merge(x , seg[2 * v]).bad == 0)
	{
		x = merge(x , seg[2 * v]);
		return max(m , GetAns(x , m , e , 2 * v + 1));
	}
	else
		return GetAns(x , s , m , 2 * v);
}

int main()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &p[i]);

	for(int i = 1; i < n; i++)
	{
		int p;
		scanf("%d", &p); p--;

		adj[p].pb(i);
	}

	dfs(0);

	int m = 2 * n - 1;
	for(int i = 0; i < m; i++)
		mn[0][i] = arr[i];

	for(int i = 2; i < maxn * 2; i++)
		hb[i] = hb[i / 2] + 1;

	for(int i = 1; i < maxb; i++)
		for(int j = 0; j < m; j++)
		{
			mn[i][j] = mn[i - 1][j];

			if(j + (1 << (i - 1)) < m)
				mn[i][j] = min(mn[i][j] , mn[i - 1][j + (1 << (i - 1))]);
		}

	for(int i = 0; i < n; i++)
		Set(p[i] , i);

	int q;
	scanf("%d", &q);

	while(q--)
	{
		int type;
		scanf("%d", &type);

		if(type == 1)
		{
			int a , b;
			scanf("%d%d", &a, &b);
			a-- , b--;

			Set(p[a] , b);
			Set(p[b] , a);
			swap(p[a] , p[b]);
		}
		else
		{
			node tmp = void_node;
			printf("%d\n", GetAns(tmp));
		}
	}
}