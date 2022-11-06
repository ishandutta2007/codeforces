#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 3e5 + 20;
const int maxm = 22;
const int mod = 998244353;

int l[maxn] , r[maxn];

int fac[maxn] , caf[maxn] , sz , pos[maxn] , sadj[maxn] , sum[maxn];

int dpt[maxm * 2] , tmp[maxm * 2];

bool visited[maxn] , has[maxn];

vector<int> adj[maxn] , cmp[maxm];

vector<int> dp[maxm][maxm];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int bpw(int a , int b)
{
	if(!b)
		return 1;

	int x = bpw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b & 1)
		x = 1LL * x * a % mod;

	return x;
}

void dfs(int v)
{
	visited[v] = 1;
	pos[v] = cmp[sz].size();
	cmp[sz].pb(v);

	for(auto u : adj[v])
		if(!visited[u])
			dfs(u);
}

int c(int s , int r)
{
	if(r > s || r < 0)
		return 0;

	return 1LL * fac[s] * caf[r] % mod * caf[s - r] % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fac[0] = 1;
	for(int i = 1; i < maxn; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;

	caf[maxn - 1] = bpw(fac[maxn - 1] , mod - 2);
	for(int i = maxn - 1; i > 0; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> l[i] >> r[i];

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		has[a] = has[b] = 1;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	for(int i = 0; i < n; i++)
		if(has[i] && !visited[i])
		{
			dfs(i);

			int k = cmp[sz].size();
			for(int j = 0; j <= k; j++)
				dp[sz][j].resize((1 << k) + 20);

			for(auto v : cmp[sz])
				for(auto u : adj[v])
					sadj[v] += (1 << pos[u]);

			for(int mask = 0; mask < (1 << k); mask++)
				for(int i = 0; i <= k; i++)
				{
					if(!i)
						dp[sz][i][mask] = 1;
					else if(mask)
					{
						int b = __builtin_ctz(mask);
						int v = cmp[sz][b];
						mkay(dp[sz][i][mask] = dp[sz][i - 1][mask ^ (1 << b) ^ (mask & sadj[v])] + dp[sz][i][mask ^ (1 << b)]);
					}
				}

			sz++;
		}

	for(int i = 0; i < n; i++)
		if(!has[i])
			sum[l[i]]++ , sum[r[i] + 1]--;

	for(int i = 1; i <= n; i++)
		sum[i] += sum[i - 1];

	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		int sumsz = 0;

		dpt[0] = 1;
		for(int j = 0; j < sz; j++)
		{
			int mask = 0 , b = 0;
			for(auto v : cmp[j])
				if(l[v] <= i && i <= r[v])
					mask += (1 << pos[v]) , b++;

			for(int x = 0; x <= sumsz; x++)
				for(int y = 0; y <= b; y++)
					mkay(tmp[x + y] += 1LL * dpt[x] * dp[j][y][mask] % mod);

			sumsz += b;
			for(int x = 0; x <= sumsz; x++)
				dpt[x] = tmp[x] , tmp[x] = 0;
		}

		for(int x = 0; x <= sumsz; x++)
			mkay(res += 1LL * c(sum[i] , i - x) * dpt[x] % mod);
	}

	cout << res << endl;
}