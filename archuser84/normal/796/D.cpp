///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 300'010;
vector<pii> A[N];
bool a[N], ans[N];
bool vis[N];
int n, k, d;

void bfs()
{
	queue<pii> q;
	Loop(i,0,n)
		if(a[i])
			q.push({i, -1}),
			vis[i] = 1;
	while(q.size())
	{
		auto [v, p] = q.front(); q.pop();
		for(auto [u, e] : A[v])
		{
			if(u == p) continue;
			if(vis[u]) {ans[e] = 1; continue;}
			q.push({u, v});
			vis[u] = 1;
		}
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k >> d;
	Loop(i,0,k)
	{
		int v;
		cin >> v; --v;
		k -= a[v]; i -= a[v];
		a[v] = 1;
	}
	Loop(i,1,n)
	{
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back({u,i});
		A[u].push_back({v,i});
	}
	bfs();
	cout << k-1 << '\n';
	Loop(i,1,n) if(ans[i]) cout << i << ' ';
	cout << '\n';
}