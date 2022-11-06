#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;
const int mod = 998244353;

array<int , 3> dp[maxn] , last;

vector<int> adj[maxn];

// 2 : v moalefe tak rasi bashe
// 0 : bejoz v moalefe kamel bashe
// 1 : v too matching bashe va moalefe kamel bashe

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

void dfs(int v , int p = -1)
{
	for(auto u : adj[v])
		if(u != p)
			dfs(u , v);

	dp[v][2] = 1;
	for(auto u : adj[v])
		if(u != p)
		{
			last = dp[v];
			dp[v].fill(0);

			// hazf she
			mkay(dp[v][2] += 1LL * last[2] * (dp[u][1] + dp[u][2]) % mod);
			mkay(dp[v][1] += 1LL * last[1] * (dp[u][1] + dp[u][2]) % mod);
			mkay(dp[v][0] += 1LL * last[0] * (dp[u][1] + dp[u][2]) % mod);

			// hazf nashe
			mkay(dp[v][2] += 0);
			mkay(dp[v][1] += 1LL * (last[0] + last[2]) * (dp[u][0] + dp[u][2]) % mod);
			mkay(dp[v][1] += 1LL * last[1] * dp[u][1] % mod);
			mkay(dp[v][0] += 1LL * (last[0] + last[2]) * dp[u][1] % mod);
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

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

	dfs(0);

	int res = dp[0][1] + dp[0][2];
	mkay(res);

	cout << res << endl;
}