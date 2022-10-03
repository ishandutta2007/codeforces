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
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, da, db, ans;
int dist[MAXN];
vector<int> G[MAXN];

pii dfs(int node, int par, int h=0){
	dist[node]=h;
	pii res={0, node};
	for (int v:G[node]) if (v!=par){
		pii p=dfs(v, node, h+1);
		p.first++;
		res=max(res, p);
	}
	return res;
}

int Solve(){
	cin>>n>>a>>b>>da>>db;
	for (int i=1; i<=n; i++) G[i].clear();
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int root=dfs(a, 0).second;
	if (dist[b]<=da) kill("Alice")
	int D=dfs(root, 0).first;
	da=min(da, D);
	db=min(db, D);
	if (db<=2*da) kill("Alice")
	// db>da*2
	kill("Bob")
	 
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