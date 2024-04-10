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
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=500010;

int n, m, k, u, v, x, y, t, a, b, L, R, root;
int deg[MAXN], dist[MAXN], Q[MAXN];
int mark[MAXN], par[MAXN], dsu[MAXN];
vector<int> G[MAXN], vec[3];

int getpar(int x){ return (dsu[x]==x?x:dsu[x]=getpar(dsu[x]));}
inline void join(int x, int y){ dsu[getpar(x)]=getpar(y);}
void print(){
	vector<int> out;
	for (int i=1; i<=n; i++) if (!mark[i]) out.pb(i);
	if (out.empty()) cout<<"No\n";
	else{
		cout<<"Yes\n"<<out.size()<<"\n";
		for (int i:out) cout<<i<<" ";
		cout<<"\n";
	}			
}
bool dfs(int x, int prv){
	mark[x]=1;
	for (int v:G[x]) if (v==root && prv) return 1;
	for (int v:G[x]) if (v!=root && v!=prv && dfs(v, x)) return 1;
	mark[x]=0;
	return 0;
}
bool Solve(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) G[i].clear(), deg[i]=mark[i]=par[i]=0;
	for (int i:{0, 1, 2}) vec[i].clear();
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
		deg[u]++, deg[v]++;
	}
	if (n<=2) kill("No")
	for (int i=1; i<=n; i++) vec[deg[i]%3].pb(i);
	if (vec[0].size()){
		int v=vec[0][0];
		mark[v]=1;
		print();
		return 0;
	}
	if (vec[2].size()){
		fill(dist+1, dist+n+1, inf);
		L=R=0;
		for (int v:vec[2]) if (dist[v]==inf){
			dist[Q[R++]=v]=0;
			while (L<R){
				int v=Q[L++];
				pii shit={inf, 0};
				for (int u:G[v]) if (deg[u]%3==2){
					if (dist[v]+1<dist[u]){
						par[u]=v;
						dist[u]=dist[v]+1;
						Q[R++]=u;
					}
					else if (u!=par[v]) shit=min(shit, pii(dist[u], u));
					
				}
				int u=shit.second;
				if (!u) continue ;
				while (v^u){
					if (dist[u]>dist[v]) swap(u, v);
					mark[v]=1;
					v=par[v];
				}
				mark[v]=1;
				print();
				return 0;			
			}
		}
	}
	if (vec[1].size()>1){
		L=R=0;
		fill(dist+1, dist+n+1, inf);
		dist[Q[R++]=vec[1][0]]=0;
		while (L<R){
			int v=Q[L++];
			if (v!=vec[1][0] && deg[v]%3==1){
				while (v){
					mark[v]=1;
					v=par[v];
				}
				print();
				return 0;
			}
			for (int u:G[v]) if (dist[v]+1<dist[u]){
				dist[u]=dist[v]+1;
				par[u]=v;
				Q[R++]=u;
			}
		}
	}
	if (vec[1].empty()) kill("No")
	root=vec[1][0];
	iota(dsu, dsu+n+1, 0);
	for (int v=1; v<=n; v++) if (v!=root) for (int u:G[v]) if (u!=root) join(u, v);
	int comp=0, c1=0, c2=0;
	for (int i=1; i<=n; i++) if (i!=root && dsu[i]==i){
		if (comp++) c2=i;
		else c1=i;
	}
	assert(comp*2%3==1);
	assert(comp%3==2);
	if (comp==2){
		int bad=0;
		for (int i=1; i<=n && !bad; i++) if (i!=root) bad&=(G[i].size()==2);
		if (bad) kill("No")
	}
	int a1=0, b1=0, a2=0, b2=0;
	for (int v:G[root]){
		if (getpar(v)==c1){
			if (a1) b1=v;
			else a1=v;
		}
		if (getpar(v)==c2){
			if (a2) b2=v;
			else a2=v;
		}
	}
	assert(dfs(a1, 0));
	assert(dfs(a2, 0));
	mark[root]=1;
	print();
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
5 5
3 5
1 4
5 2
1 5
4 5

*/