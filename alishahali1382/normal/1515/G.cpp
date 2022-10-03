#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int comp[MAXN], mark[MAXN];
ll ans[MAXN], H[MAXN];
vector<pii> G[MAXN], GR[MAXN];
vector<int> topol;

void dfs1(int node){
	comp[node]=-1;
	for (pii p:G[node]) if (comp[p.first]!=-1) dfs1(p.first);
	topol.pb(node);
}
void dfs2(int node, int cid){
	comp[node]=cid;
	for (pii p:GR[node]) if (comp[p.first]==-1) dfs2(p.first, cid);
}
void dfs3(int node){
	mark[node]=1;
	for (pii p:G[node]){
		int v=p.first, x=p.second;
		if (!mark[v]){
			H[v]=H[node]+x;
			dfs3(v);
		}
		else{
			ans[comp[node]]=__gcd(ans[comp[node]], H[node]-H[v]+x);
//			debug2(node, v)
//			debug(H[node]-H[v]+x)
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v>>x;
		G[u].pb({v, x});
		GR[v].pb({u, x});
	}
	for (int i=1; i<=n; i++) if (comp[i]!=-1) dfs1(i);
	reverse(all(topol));
	for (int v:topol) if (comp[v]==-1) dfs2(v, v);
	for (int i=1; i<=n; i++) G[i].clear();
	for (int v=1; v<=n; v++){
		for (pii p:GR[v]){
			int u=p.first, x=p.second;
			if (comp[u]!=comp[v]) continue ;
			// u -x-> v 
//			cerr<<"add_edge "<<u<<" "<<v<<" "<<x<<"\n";
			G[u].pb({v, x});
			G[v].pb({u, -x});
		}
	}
	for (int v=1; v<=n; v++) if (!mark[v]) dfs3(v);
//	debug(ans[1])
	cin>>m;
	while (m--){
		cin>>v>>x>>y;
		ll g=__gcd(ans[comp[v]], 1ll*y);
		x=y-x;
		if (x%g) cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}