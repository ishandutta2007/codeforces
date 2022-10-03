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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN], h[MAXN];
pii mark[MAXN];
vector<int> G[MAXN], v1, v2, v3;
vector<pii> E;

void dfs(int node){
	h[node]=h[par[node]]+1;
	for (int v:G[node]) if (v!=par[node]){
		if (!h[v]) par[v]=node, dfs(v);
		else if (h[v]<h[node]) E.pb({node, v});
	}
}

void done(){
	cout<<"YES\n";
	cout<<v1.size()<<' ';for (int i:v1) cout<<i<<' ';cout<<'\n';
	cout<<v2.size()<<' ';for (int i:v2) cout<<i<<' ';cout<<'\n';
	cout<<v3.size()<<' ';for (int i:v3) cout<<i<<' ';cout<<'\n';
	exit(0);
}

int Lca(int x, int y){
	while (x!=y){
		if (h[x]<h[y]) swap(x, y);
		x=par[x];
	}
	return x;
}

void found(pii p1, pii p2){
//	debugp(p1)
//	debugp(p2)
	if (h[p1.first]<h[p2.first]) swap(p1, p2);
	int x=Lca(p1.first, p2.first), v;
	int y=p2.second, a=p2.first;
	int z=p1.second, b=p1.first;
	if (h[y]<h[z]) swap(y, z), swap(a, b);
	
//	debug2(x, y)
//	debug2(a, b)
	
	v=x;
	while (1){
		v1.pb(v);
		if (v==y) break ;
		v=par[v];
	}
	
	v=y;
	while (1){
		v2.pb(v);
		if (v==z) break ;
		v=par[v];
	}
	v=b;
	while (1){
		v2.pb(v);
		if (v==x) break ;
		v=par[v];
	}
	reverse(all(v2));
	
	v3.pb(y);
	v=a;
	while (1){
		v3.pb(v);
		if (v==x) break ;
		v=par[v];
	}
	reverse(all(v3));
	
	done();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++) if (!h[i]) dfs(i);
	for (pii p:E){
		int v=p.first;
		while (v!=p.second){
			if (mark[v].first) found(mark[v], p);
			mark[v]=p;
			v=par[v];
		}
	}
	kill("NO")
	
	return 0;
}