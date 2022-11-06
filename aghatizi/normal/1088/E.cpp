#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

int a[maxn];
ll dp[maxn] , ans = -1e18 , T , rem[maxn];

vector<int> adj[maxn];

void plant(int v , int p = -1)
{
	dp[v] = a[v];
	for(auto u : adj[v])
		if(u != p)
		{
			plant(u , v);
			dp[v] += max(0LL , dp[u]);
		}

	if(dp[v] == ans)
		T++ , dp[v] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	plant(0);
	ans = *max_element(dp , dp + n);
	plant(0);

	cout << T * ans << " " << T << endl;
}