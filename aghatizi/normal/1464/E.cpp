#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;
const int N = 1024;
const int mod = 998244353;

vector<int> adj[maxn];

int g[maxn] , ct[maxn] , cnt[maxn];

bool visited[maxn];

void dfs(int v)
{
	visited[v] = 1;

	for(auto u : adj[v])
		if(!visited[u])
			dfs(u);

	for(auto u : adj[v])
		ct[g[u]]++;

	while(ct[g[v]])
		g[v]++;

	for(auto u : adj[v])
		ct[g[u]]--;
}

int bpw(int a , int b)
{
	int ans = 1;
	while(b)
	{
		if(b & 1)
			ans = 1LL * ans * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}

	return ans;
}

void fwht(int* a , int val)
{
	for(int len = 2; len <= N; len *= 2)
		for(int i = 0; i < N; i += len)
		{
			int nxt = len / 2;
			for(int j = 0; j < nxt; j++)
			{
				int x = a[i + j] , y = a[i + j + nxt];

				a[i + j] = (x + y) % mod;
				a[i + j + nxt] = (x - y + mod) % mod;
			}
		}

	if(val == -1)
	{
		int inv = bpw(N , mod - 2);
		for(int i = 0; i < N; i++)
			a[i] = 1LL * a[i] * inv % mod;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
	}

	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
			dfs(i);
		cnt[g[i]]++;
	}

	int inv = bpw(n + 1 , mod - 2);
	for(int i = 0; i < N; i++)
		cnt[i] = 1LL * cnt[i] * inv % mod;

	fwht(cnt , 1);

	for(int i = 0; i < N; i++)
		cnt[i] = 1LL * bpw((1 - cnt[i] + mod) % mod , mod - 2) * inv % mod;

	fwht(cnt , -1);

	cout << (1 - cnt[0] + mod) % mod << endl;
}