#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
#define lb(a) ((a)&(-(a)))

const int maxn = 1e5 + 20;
const int maxb = 20;

vector<int> adj[maxn];

vector<pair<int , int> > askc[maxn] , asko[maxn];

int par[maxn][maxb] , h[maxn] , st[maxn] , ft[maxn] , now = -1;

int type[maxn] , a[maxn] , b[maxn] , k[maxn] , y[maxn] , pos[maxn];

int Lca[maxn] , res[maxn] , ans[maxn] , tmp[maxn];

void plant(int v , int p = -1)
{
	st[v] = ++now;

	for(auto u : adj[v])
		if(u != p)
		{
			par[u][0] = v;
			for(int i = 1; i < maxb; i++)
				par[u][i] = par[par[u][i - 1]][i - 1];

			h[u] = h[v] + 1;

			plant(u , v);
		}

	ft[v] = now;
}

bool is_par(int v , int u)
{
	return st[v] <= st[u] && st[u] <= ft[v];
}

int lca(int v , int u)
{
	if(is_par(v , u))
		return v;

	for(int i = maxb - 1; i >= 0; i--)
		if(!is_par(par[v][i] , u))
			v = par[v][i];

	return par[v][0];
}

int go(int v , int H)
{
	for(int i = 0; i < maxb; i++)
		if((H>>i)&1)
			v = par[v][i];

	return v;
}

int fen[maxn];

void upd(int p , int val)
{
	for(p += 5; p < maxn; p += lb(p))
		fen[p] += val;
}

int get(int p)
{
	int res = 0;
	for(p += 5; p > 0; p -= lb(p))
		res += fen[p];

	return res;
}

void dfs(int v , int p = -1)
{
	for(auto ind : askc[v])
		res[ind.second] -= h[v] - (get(ind.second) - get(ind.first));

	for(auto ind : asko[v])
		res[ind.second] += h[v] - (get(ind.second) - get(ind.first));

	if(pos[v] != -1)
		upd(pos[v] , 1);

	for(auto u : adj[v])
		if(u != p)
			dfs(u , v);

	if(pos[v] != -1)
		upd(pos[v] , -1);
}

int q;

void handle()
{
	memset(fen , 0 , sizeof fen);
	memset(res , 0 , sizeof res);

	dfs(0);

	for(int i = 0; i < maxn; i++)
		asko[i].clear() , askc[i].clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(pos , -1 , sizeof pos);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		p--;

		if(p >= 0)
			adj[p].pb(i) , adj[i].pb(p);
	}

	plant(0);

	cin >> q;

	for(int i = 0; i < q; i++)
	{
		cin >> type[i];

		if(type[i] == 1)
		{
			cin >> a[i];
			a[i]--;

			pos[a[i]] = i;
		}
		else
		{
			cin >> a[i] >> b[i] >> k[i] >> y[i];
			a[i]-- , b[i]--;
			y[i]--;

			Lca[i] = lca(a[i] , b[i]);

			if(Lca[i] == a[i])
			{
				int shit = go(b[i] , h[b[i]] - h[a[i]] - 1);

				askc[shit].pb({y[i] , i});
				asko[b[i]].pb({y[i] , i});
			}
			else if(Lca[i] == b[i])
			{
				int shit = go(a[i] , h[a[i]] - h[b[i]] - 1);

				askc[shit].pb({y[i] , i});
				asko[a[i]].pb({y[i] , i});
			}
			else
			{
				askc[Lca[i]].pb({y[i] , i});
				asko[a[i]].pb({y[i] , i});
			}
		}
	}

	handle();

	for(int i = 0; i < q; i++)
		if(type[i] == 2)
		{
			tmp[i] = res[i];

			if(a[i] != Lca[i] && b[i] != Lca[i])
			{
				int shit = go(b[i] , h[b[i]] - h[Lca[i]] - 1);

				askc[shit].pb({y[i] , i});
				asko[b[i]].pb({y[i] , i});
			}
		}

	handle();

	for(int i = 0; i < q; i++)
		if(type[i] == 2)
		{
			if(tmp[i] + res[i] < k[i])
			{
				ans[i] = -1;
				continue;
			}

			if(a[i] == Lca[i])
				a[i] = go(b[i] , h[b[i]] - h[a[i]] - 1);
			else if(b[i] == Lca[i])
				b[i] = go(b[i] , h[a[i]] - h[b[i]] - 1);
			else
			{
				if(tmp[i] < k[i])
				{
					k[i] -= tmp[i];
					int shit = go(b[i] , h[b[i]] - h[Lca[i]] - 1);

					a[i] = shit;
				}
				else
					b[i] = Lca[i];
			}

		}

	for(int i = maxb - 1; i >= 0; i--)
	{
		for(int j = 0; j < q; j++)
			if(type[j] == 2 && ans[j] != -1 && abs(h[b[j]] - h[a[j]]) > (1 << i))
			{
				if(is_par(a[j] , b[j]))
				{
					int shit = par[b[j]][i];

					askc[a[j]].pb({y[j] , j});
					asko[shit].pb({y[j] , j});
				}
				else
				{
					int shit = par[a[j]][i];

					askc[shit].pb({y[j] , j});
					asko[a[j]].pb({y[j] , j});
				}
			}

		handle();

		for(int j = 0; j < q; j++)
			if(type[j] == 2 && ans[j] != -1 && abs(h[b[j]] - h[a[j]]) > (1 << i))
			{
				if(is_par(a[j] , b[j]))
				{
					if(res[j] >= k[j])
						b[j] = par[b[j]][i];
					else
					{
						k[j] -= res[j];

						a[j] = par[b[j]][i];
					}
				}
				else
				{
					if(res[j] >= k[j])
						b[j] = par[a[j]][i];
					else
					{
						k[j] -= res[j];

						a[j] = par[a[j]][i];
					}
				}
			}
	}

	for(int i = 0; i < q; i++)
		if(type[i] == 2)
		{
			if(ans[i] == -1)
				cout << -1 << endl;
			else
			{
				if(is_par(a[i] , b[i]))
					cout << a[i] + 1 << endl;
				else
					cout << b[i] + 1 << endl;
			}
		}

}