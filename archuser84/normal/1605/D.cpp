#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x=(l);x<(r);++x)
#define LoopR(x,l,r) for(ll x=(r)-1;x>=(l);--x)
typedef long long ll;
using namespace std;

const int N = 200'010;
bool vis[N];
bool viss[N];
vector<int> dard[2];
vector<int> A[N];

void dfs(int v, bool b=0)
{
	vis[v] = 1;
	dard[b].push_back(v);
	for(int u : A[v])
		if(!vis[u])
			dfs(u,!b);
}

int ans[N];
void solve()
{
	int n;
	cin >> n;
	Loop(i,0,n) A[i].clear();
	Loop(i,1,n)
	{
		int v, u;
		cin>>v>>u; --v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	memset(viss,0,n);
	int cnt = 2<<__lg(n);
	int nn=n;
	LoopR(k,0,18)
	{

		Loop(v,0,n) vis[v] = viss[v];
		dard[1].clear();
		dard[0].clear();
		Loop(v,0,n)
			if(!vis[v])
				dfs(v);
		if(dard[0].size() < dard[1].size()) dard[0].swap(dard[1]);
		while(--cnt >= (1<<k)) if(cnt <= n){
			viss[dard[0].back()] = 1;
			ans[dard[0].back()] = cnt;
			dard[0].pop_back();
		} ++cnt;
	}
	Loop(i,0,nn) cout << ans[i] << ' ';
	cout << '\n';
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}