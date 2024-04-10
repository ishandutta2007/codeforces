#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;
const int mx = ((1LL << 62) - 1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int n, m, ans = 0, cnt = 0;
vector<int> g[N];
int store[N], hashVal[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	for(int i = 1; i <= n; i++)
		store[i] = getRand(0, mx);
	for(int i = 1; i <= n; i++)
	{
		for(auto &it:g[i])
			hashVal[i] ^= store[it];
	}
	map<int, int> m;
	for(int i = 1; i <= n; i++)
	{
		ans += m[hashVal[i]];
		m[hashVal[i]]++;
		for(auto &it:g[i])
			cnt += (hashVal[i] ^ store[it]) == (hashVal[it] ^ store[i]);
	}
	ans += cnt / 2;
	cout << ans;
	return 0;
}