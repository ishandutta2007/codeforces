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
const int MAXN=300010, SQ=320;

int n, m, k, u, v, x, y, t, a, b, ans;
int sz[MAXN], mark[MAXN];
vector<int> V[MAXN];
vector<pii> adj[MAXN];

int Solve(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) adj[i].clear();
	for (int i=1; i<=m; i++){
		cin>>sz[i];
		V[i].resize(sz[i]);
		for (int j=0; j<sz[i]; j++) cin>>V[i][j];
		if (sz[i]<=SQ){
			for (int x=0; x<sz[i]; x++) for (int y=x+2; y<sz[i]; y++)
				adj[V[i][x]].pb({V[i][y], V[i][x+1]});
		}
	}
	for (int a=1; a<=n; a++){
		bool sik=0;
		for (pii p:adj[a]){
			if (mark[p.first]!=p.second && mark[p.first]!=-1){
				sik=1;
				break ;
			}
			mark[p.first]=p.second;
		}
		for (pii p:adj[a]) mark[p.first]=-1;
		if (sik) kill("Human")
	}
//	debug("shit")
	for (int i=1; i<=m; i++) if (sz[i]>SQ){
		for (int x=0; x<sz[i]; x++) mark[V[i][x]]=x;
		bool sik=0;
		for (int j=1; j<=m && !sik; j++) if (i!=j){
			int mx=-1;
			for (int x=sz[j]-1; ~x; x--){
				int a=V[j][x];
				if (mark[a]==-1) continue ;
				mx=max(mx, mark[a]);
				if (mark[a]<mx && V[i][mark[a]+1]!=V[j][x+1]){
					sik=1;
					break ;
				}
			}
		}
		for (int x=0; x<sz[i]; x++) mark[V[i][x]]=-1;
		if (sik) kill("Human")
	}
	kill("Robot")
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(mark, -1, sizeof(mark));
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
10
10
2 4 7
2 8 7
2 4 7
3 10 4 7
2 4 7
3 2 7 9
4 10 4 7 9
2 7 9
3 2 7 9
3 1 7 9

*/