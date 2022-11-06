#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxb = 17;
const int N = (1 << maxb);
const int maxn = N + 20;
const int maxk = 43;

const int Mod[] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
int mod;

int from[maxn] , to[maxn] , w[maxn] , par[maxn] , h[maxn] , cnt , ans[2][maxk][maxn];

vector<int> adj[maxn] , val[maxn];

bool visited[maxn] , in_cycle[maxn];

void dfs(int v , int pe = -1)
{
	visited[v] = 1;
	for(auto e : adj[v])
	{
		int u = from[e] ^ to[e] ^ v;
		if(e == pe)
			continue;
		if(!visited[u])
		{
			par[u] = e;
			h[u] = h[v] + 1;
			dfs(u , e);
		}
		else if(h[v] < h[u])
		{
			in_cycle[e] = 1;
			val[cnt].pb(w[e]);
			while(u != v)
			{
				int te = par[u];
				in_cycle[te] = 1;
				val[cnt].pb(w[te]);
				u = from[te] ^ to[te] ^ u;
			}
			cnt++;
		}
	}
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
		cin >> a >> b >> w[i];
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	dfs(0);

	int s = 0;
	for(int i = 0; i < m; i++)
		s ^= w[i];

	if(!cnt)
		return cout << s << " " << 1 << endl , 0;

	for(int ind = 0; ind < 2; ind++)
	{
		mod = Mod[ind];
		for(int i = 0; i < cnt; i++)
		{
			for(auto x : val[i])
				ans[ind][i][x]++;
			fwht(ans[ind][i] , 1);
			for(int j = 0; j < N && i; j++)
				ans[ind][0][j] = 1LL * ans[ind][0][j] * ans[ind][i][j] % mod;
		}

		fwht(ans[ind][0] , -1);
	}

	for(int i = 0; i < N; i++)
		if(ans[0][0][i ^ s] != 0 || ans[1][0][i ^ s] != 0)
		{
			cout << i << " " << ans[0][0][i ^ s] << endl;
			break;
		}
}