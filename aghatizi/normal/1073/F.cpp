#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define X first
#define Y second

const int maxn = 2e5 + 20;

vector<int> adj[maxn];

int par[maxn] , x[maxn] , ver[maxn] , A[maxn] , B[maxn] , total , St[maxn];

int mxlen , mxsum , a , b;

bool hide[maxn];

void predfs(int v , int p = -1)
{
	int T = 0;

	if((int)adj[v].size() > 2)
		St[v] = 1;

	for(auto u : adj[v])
		if(u != p)
		{
			predfs(u , v);
			St[v] += St[u];
			par[u] = v;

			T += !hide[u];
		}

	if(T > 1 || (int)adj[v].size() > 2 || (St[v] > 0 && total != St[v]))
		hide[v] = 0;
}

void get(int v , int p = -1)
{
	ver[v] = v;
	for(auto u : adj[v])
		if(u != p && hide[u])
		{
			get(u , v);

			if(x[u] + 1 > x[v])
				x[v] = x[u] + 1 , ver[v] = ver[u];
		}

	if(!hide[v])
	{
		A[v] = ver[v];

		int tmpmx = -1e9;

		for(auto u : adj[v])
			if(u != p && hide[u] && A[v] != ver[u] && x[u] > tmpmx)
			{
				B[v] = ver[u];
				tmpmx = x[u];
			}

		x[v] += tmpmx + 1;
	}
}

pair<pair<int , int> , int> solve(int v , int p = -1)
{
	pair<pair<int , int> , int> mx = {{0 , x[v]} , v};

	for(auto u : adj[v])
		if(!hide[u] && u != p)
		{
			auto tmp = solve(u , v);
			tmp.X.X++;

			if(make_pair(mx.X.X + tmp.X.X , mx.X.Y + tmp.X.Y) > make_pair(mxlen , mxsum))
			{
				a = mx.Y;
				b = tmp.Y;
				mxlen = mx.X.X + tmp.X.X;
				mxsum = mx.X.Y + tmp.X.Y;
			}

			mx = max(mx , tmp);
		}

	return mx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(hide , 1 , sizeof hide);

	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	for(int i = 0; i < n; i++)
		if((int)adj[i].size() > 2)
			total++;

	predfs(0);

	int root = 0;
	for(int i = 0; i < n; i++)
		if(!hide[i])
			get(i) , root = i;

	solve(root);

	cout << A[a] + 1 << " " << A[b] + 1 << endl;
	cout << B[a] + 1 << " " << B[b] + 1 << endl;
}