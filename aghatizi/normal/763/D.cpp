#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int base = 4001;
const int mod = 1e9 + 7;

vector<int> adj[maxn];

map<int , int> mp;

int res[maxn] , h[maxn] , sz;

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

inline int bpw(int a , int b)
{
	if(!b)
		return 1;

	int x = bpw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

inline void handle(int h , int val)
{
	if(val == -1)
		sz -= (mp[h] == 1);
	else
		sz += (mp[h] == 0);

	mp[h] += val;
}

void plant(int v , int p = -1)
{
	h[v] = 1;
	for(auto u : adj[v])
		if(u != p)
		{
			plant(u , v);

			mkay(h[v] += bpw(base , h[u]));
		}

	handle(h[v] , 1);
}

void dfs(int v , int p = -1)
{
	res[v] = sz;

	for(auto u : adj[v])
		if(u != p)
		{
			handle(h[v] , -1);
			mkay(h[v] -= bpw(base , h[u]));
			handle(h[v] , 1);

			handle(h[u] , -1);
			mkay(h[u] += bpw(base , h[v]));
			handle(h[u] , 1);

			dfs(u , v);

			handle(h[u] , -1);
			mkay(h[u] -= bpw(base , h[v]));
			handle(h[u] , 1);

			handle(h[v] , -1);
			mkay(h[v] += bpw(base , h[u]));
			handle(h[v] , 1);
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

	plant(0);
	dfs(0);

	pair<int , int> mx = {-1 , 0};

	for(int i = 0; i < n; i++)
		mx = max(mx , make_pair(res[i] , -i));

	cout << -mx.second + 1 << endl;
}