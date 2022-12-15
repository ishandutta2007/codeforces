#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans, root;
int h[MAXN];
bool mark[MAXN];
vector<int> G[MAXN];


void dfs(int node, int par){
	for (int v:G[node]) if (v!=par){
		h[v]=h[node]+1;
		dfs(v, node);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; !root; i++) if (G[i].size()==1) root=i;
	dfs(root, 0);
	ans=1;
	for (int i=1; i<=n; i++) if (h[i]%2==1 && G[i].size()==1) ans=3;
	cout<<ans<<' ';
	ans=n-1;
	for (int i=1; i<=n; i++) if (G[i].size()==1){
		int v=G[i][0];
		if (mark[v]) ans--;
		mark[v]=1;
	}
	cout<<ans<<'\n';
	
	
	return 0;
}