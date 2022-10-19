#include<bits/stdc++.h>
#define int long long
#define N 300015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,m,bel[N],Gcd[N],vis[N];
VI b[N];
vector<pii> e[N],g[N];
namespace Kosaraju{
	int vis[N],scc;
	VI s;
	void dfs1(int u){
		vis[u] = 1;
		for(auto V:e[u]){
			int v = V.fi;
			if(!vis[v]) dfs1(v);
		}
		s.pb(u);
	}
	void dfs2(int u){
		bel[u] = scc;
		for(auto V:g[u]){
			int v = V.fi;
			if(!bel[v]) dfs2(v);
		}
	}
	void solve(){
		s.pb(0);
		rep(i,1,n){
			if(!vis[i]) dfs1(i);
		}
		per(i,1,n){
			if(!bel[s[i]]) {
				scc++;
				dfs2(s[i]);
			}
		}
	}
}
int dep[N];
vector<pair<pii,int> > non; //non-tree edges
void dfs(int u,int scc){
	for(auto V:e[u]){
		int v = V.fi,w = V.se;
		if(bel[v] == scc && dep[v]) non.pb(mp(mp(u,v),w));
		if(bel[v] != scc || dep[v]) continue;
		dep[v] = dep[u]+w;
		dfs(v,scc);
	}
}
void get(int scc){
	for(auto u:b[scc]) dep[u] = 0;
	non.clear();
	dep[b[scc][0]] = 1;
	dfs(b[scc][0],scc);
	for(auto x:non){
		int u = x.fi.fi,v = x.fi.se,w = x.se;
		int len = dep[u]-dep[v]+w;
		if(!Gcd[scc]) Gcd[scc] = len;
		else Gcd[scc] = __gcd(Gcd[scc],len);
	}
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	rep(i,1,m){
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		e[u].pb(mp(v,w)); g[v].pb(mp(u,w));
	}
	Kosaraju::solve();
	rep(i,1,n) b[bel[i]].pb(i);
	// rep(i,1,n) printf("%lld ",bel[i]);

	// printf("\n");
	rep(i,1,n){
		if(!vis[bel[i]]){
			vis[bel[i]] = 1;
			get(bel[i]);
		}
	}
	// rep(i,1,2) printf("%lld\n", Gcd[i]);
	int q; scanf("%lld",&q);
	while(q--){
		int v,s,t;
		scanf("%lld%lld%lld",&v,&s,&t);
		if((t-s)%__gcd(Gcd[bel[v]],t) == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}