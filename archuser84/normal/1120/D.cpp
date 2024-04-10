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

#define int ll

const int N = 200'010;
vector<int> A[N];
int a[N];
int n;

ll sum[N], mx[N]; set<ll> mxv[N];
bool padoru[N], nero[N];

pair<ll,ll> dfs(int v, int p)
{
	sum[v]=0; mx[v]=-1;
	for(int u : A[v]){
		if(u == p) continue;
		auto [x, y] = dfs(u, v);
		sum[v] += x;
		if(x-y > mx[v]){
			mx[v] = x-y;
			mxv[v].clear();
		}
		if(x-y == mx[v]) mxv[v].insert(u);
	}
	if(mx[v]==-1) {padoru[v]=1; nero[v]=0; return {a[v], 0};}
	if(sum[v] >= a[v]+sum[v]-mx[v]) padoru[v] = 1;
	if(sum[v] <= a[v]+sum[v]-mx[v]) nero[v] = 1;
	return {min(sum[v], a[v]+sum[v]-mx[v]), sum[v]-mx[v]};
}

set<int> ans;
bool vis[2][N];
void dfs2(int v, int p, bool s)
{
	if(vis[s][v]) return;
	vis[s][v] = 1;
	if(!s && padoru[v]) ans.insert(v);
	for(int u : A[v]){
		if(u==p) continue;
		if((s || padoru[v]) && mxv[v].count(u))
			dfs2(u, v, 1);
		else
			dfs2(u, v, 0);
		if((!s && nero[v]) || mxv[v].size() > 1)
			dfs2(u, v, 0);
	}
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) cin >> a[i];
	Loop(i,1,n){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	cout << dfs(0, -1).first << ' ';
	dfs2(0, -1, 0);
	cout << ans.size() << '\n';
	for(auto v : ans) cout << v+1 << ' ';
	cout << '\n';
}