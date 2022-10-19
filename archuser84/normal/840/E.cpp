///
///    Let the voice of love take you higher! 
///

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;

#define smax(x,y) (x)=(x)>(y)?(x):(y)

const int N = 50'010;
int st[N];
int sp = N;
int h[N];
int a[N];
int ans[3*N];
vector<pair<int,int>> Q[N];
vector<int> A[N];
int n, q;

void dfs(int v, int p, int hh)
{
	h[v] = hh;
	st[--sp] = a[v];
	for(auto [u, q] : Q[v])
	{
		int k = h[v]-h[u]+1;
		int ans = 0;
		for(int i = 0; i < k; ++i)
			smax(ans,i^st[sp+i]);
		::ans[q] = ans;
	}
	for(int u : A[v])
		if(u != p)
			dfs(u, v, hh+1);
	++sp;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int _ = 1; _ < n; ++_)
	{
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	for(int i = 0; i < q; ++i)
	{
		int v, u;
		cin >> u >> v;
		--v; --u;
		Q[v].emplace_back(u, i);
	}
	dfs(0,-1,0);
	for(int i = 0; i < q; ++i)
		cout << ans[i] << '\n';
}