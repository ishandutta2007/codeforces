#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int sq = 1000;

vector<int> adj[maxn] , topol;

int k , ans[maxn] , rem[maxn] , dp[maxn];

void plant(int v , int p = -1)
{
	vector<int> tmp;

	for(auto u : adj[v])
		if(u != p)
		{
			tmp.pb(u);
			plant(u , v);
		}

	adj[v].swap(tmp);
	topol.pb(v);
}

void dfs(int v)
{
	for(auto v : topol)
	{
		dp[v] = rem[v] = 0;
		int mx1 = 0 , mx2 = 0;

		for(int u : adj[v])
		{
			dp[v] += dp[u];

			if(rem[u] >= mx2)
			{
				mx1 = mx2;
				mx2 = rem[u];
			}
			else if(rem[u] >= mx1)
				mx1 = rem[u];
		}

		if(mx1 + mx2 + 1 >= k)
			dp[v]++;
		else
			rem[v] = mx2 + 1;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	plant(0);

	for(int i = 1; i <= sq && i <= n; i++)
	{
		k = i;
		dfs(0);
		ans[i] = dp[0];
	}

	if(n > sq)
	{
		int X = ans[sq] , P = sq;

		while(X > 0)
		{
			int l = P , r = n + 1;

			while(r - l > 1)
			{
				int m = (l + r) / 2;
				k = m;
				dfs(0);

				if(dp[0] == X)
					l = m;
				else
					r = m;
			}

			for(int i = P; i < r; i++)
				ans[i] = X;

			k = r;
			dfs(0);
			X = dp[0];
			P = r;
		}
	}

	for(int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
}