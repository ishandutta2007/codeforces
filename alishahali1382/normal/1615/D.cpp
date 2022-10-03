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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define get(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;


int n, m, k, u, v, x, y, t, a, b, ans;
int col[MAXN];
int E[MAXN][3];
vector<pii> G[MAXN];

int dfs(int node, int c){
	if (col[node]!=-1) return col[node]==c;
	col[node]=c;
	for (pii p:G[node]) if (!dfs(p.first, c^p.second)) return 0;
	return 1;
}

int Main(){
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		col[i]=-1;
		G[i].clear();
	}
	for (int i=1; i<n; i++){
		cin>>E[i][0]>>E[i][1]>>E[i][2];
		if (E[i][2]!=-1){
			int x=__builtin_popcount(E[i][2])&1;
			G[E[i][0]].pb({E[i][1], x});
			G[E[i][1]].pb({E[i][0], x});
		}
	}
	while (m--){
		cin>>u>>v>>x;
		G[u].pb({v, x});
		G[v].pb({u, x});
	}
	for (int i=1; i<=n; i++) if (col[i]==-1 && !dfs(i, 0)) kill("NO")
	cout<<"YES\n";
	for (int i=1; i<n; i++){
		int u=E[i][0], v=E[i][1], w=E[i][2];
		if (w!=-1) cout<<u<<" "<<v<<" "<<w<<"\n";
		else{
			w=col[u]^col[v];
			cout<<u<<" "<<v<<" "<<w<<"\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
9
000011111
011100011

*/