#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, root;
int par[MAXN];
ll dp[MAXN], sz[MAXN], ans=INF;
vector<int> G[MAXN];

struct CHT{
	pair<int, pll> A[MAXN];
	int l, r;
	void reset(){
		l=r=0;
		A[r++]={inf, {inf, INF}};
	}
	inline ll Inter(pll a, pll b){
		if (a.first==b.first){
			if (a.second>=b.second) return -INF;
			return INF;
		}
		return (b.second-a.second+a.first-b.first-1)/(a.first-b.first);
	}
	inline void Add(pll a){
		while (A[r-1].first<=Inter(A[r-1].second, a)) r--;
		A[r]={Inter(A[r-1].second, a), a};
		r++;
	}
	inline ll Get(ll x){
		while (l+1<r && A[l+1].first<=x) l++;
		return A[l].second.first*x + A[l].second.second; 
	}
} cht;

inline ll C2(ll n){ return n*(n-1)/2;}
void dfs(int node){/*
	for (int &v:G[node]) if (v==par[node]) swap(G[node].back(), v);
	if (G[node].back()==par[node]) G[node].pop_back();*/
	for (int v:G[node]) if (v!=par[node]){
		par[v]=node;
		dfs(v);
		sz[node]+=sz[v];
	}
	dp[node]=C2(++sz[node]);
	for (int v:G[node]) if (v!=par[node])
		dp[node]=min(dp[node], C2(sz[node]-sz[v])+dp[v]);
//	debug2(node, dp[node])
	sort(all(G[node]), [](int i, int j){
		return sz[i]>sz[j];
	});
	
	cht.reset();
	for (int v:G[node]) if (v!=par[node]){
//		debug2(v, cht.Get(sz[v]))
		ans=min(ans, -C2(sz[v])-n*sz[v]+dp[v]+sz[v]*sz[v] + cht.Get(sz[v]));
		cht.Add({sz[v], C2(n-sz[v])+dp[v]});
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	if (n==2) kill(2)
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n && !root; i++) if (G[i].size()>1) root=i; 
	dfs(root);
	debug(ans)
	cout<<2*C2(n)-ans<<"\n";
	
	return 0;
}