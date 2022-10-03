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
const int MAXN=500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int h[MAXN], deg[MAXN], par[MAXN];
vector<pii> out;
vector<int> G[MAXN], vec;

void dfs(int node){
	h[node]=h[par[node]]+1;
	for (int v:G[node]) if (!h[v]){
		par[v]=node;
		dfs(v);
		deg[node]++;
	}
}

void Solve(){
	out.clear();
	vec.clear();
	cin>>n>>m;
	k=(n+1)/2;
	for (int i=1; i<=n; i++) G[i].clear(), h[i]=deg[i]=par[i]=0;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++){
		if (!h[i]) dfs(i);
		if (!deg[i]) vec.pb(i);
		if (h[i]==k){
			cout<<"PATH\n"<<k<<"\n";
			int v=i;
			while (v){
				cout<<v<<' ';
				v=par[v];
			}
			return ;
		}
	}
	while (vec.size()>=2){
		int u=vec.back();
		vec.pop_back();
		int v=vec.back();
		vec.pop_back();
		out.pb({u, v});
		if (par[u] && (--deg[par[u]])==0) vec.pb(par[u]);
		if (par[v] && (--deg[par[v]])==0) vec.pb(par[v]);
	}
	cout<<"PAIRING\n"<<out.size()<<"\n";
	for (pii p:out) cout<<p.first<<' '<<p.second<<"\n";
	assert(2*out.size()>=k);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int Test;
	cin>>Test;
	while (Test--) Solve();
	
	return 0;
}
/*
1
12 14
1 2
2 3
3 4
4 1
1 5
1 12
2 6
2 7
3 8
3 9
4 10
4 11
2 4
1 3

*/