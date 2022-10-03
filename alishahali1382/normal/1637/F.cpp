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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans, root;
int A[MAXN], par[MAXN];
ll dp[MAXN][2][2], dpt[MAXN][3][2][2];
vector<int> G[MAXN];

int dfs1(int node){
	for (int v:G[node]) if (v!=par[node]){
		par[v]=node;
		A[node]=max(A[node], dfs1(v));
	}
	return A[node];
}
inline void _upd(ll &x, ll y){ if (x>y) x=y;}
void dfs2(int node){
//	if (SZ(G[node])==1 && par[node]){
//		return ;
//	}
	for (int v:G[node]) if (v!=par[node]) dfs2(v);
	
	memset(dpt[0], 63, sizeof(dpt[0]));
	
	dpt[0][0][0][0]=0;
	dpt[0][1][0][1]=0;
	dpt[0][1][1][0]=0;
	dpt[0][2][1][1]=0;
	dpt[0][1][0][0]=A[node];
	dpt[0][2][0][1]=A[node];
	
	int i=0;
	for (int v:G[node]) if (v!=par[node]){
		
		i++;
		memset(dpt[i], 63, sizeof(dpt[i]));
		for (int x:{0, 1, 2}) for (int y:{0, 1}) for (int z:{0, 1}){
			_upd(dpt[i][x][y][z], dpt[i-1][x][y][z] + dp[v][0][0]);
			
			/*if (x || z) */_upd(dpt[i][x][y][z], dpt[i-1][x][y][z] + dp[v][0][1]);
			
			if (!y) _upd(dpt[i][min(x+1, 2)][1][z], dpt[i-1][x][y][z] + dp[v][1][0]);
			_upd(dpt[i][min(x+1, 2)][y][z], dpt[i-1][x][y][z] + dp[v][1][0]+A[node]);
			
			
			/*if (x || z)*/{
				if (!y) _upd(dpt[i][min(x+1, 2)][1][z], dpt[i-1][x][y][z] + dp[v][1][1]);
				_upd(dpt[i][min(x+1, 2)][y][z], dpt[i-1][x][y][z] + dp[v][1][1]+A[node]);
			}
		}
		
//		if (node==2 && i==1) debug2(i, dpt[i][1][0][0])
		
		
	}
	for (int x:{0, 1}) for (int y:{0, 1}) dp[node][x][y]=dpt[i][2][x][y];
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	root=max_element(A+1, A+n+1)-A;
	dfs1(root);
	dfs2(root);
	
	cout<<dp[root][0][0]<<"\n";
	
	return 0;
}
/*
2
1 2
1 2

*/