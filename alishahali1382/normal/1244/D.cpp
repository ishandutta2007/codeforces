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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int C[MAXN][3];
int out[MAXN];
bool mark[MAXN];
vector<int> G[MAXN], path;

void dfs(int node, int par){
	for (int v:G[node]) if (v!=par){
		path.pb(v);
		dfs(v, node);
	}
}

ll cost(int c1, int c2){
	if (c1==c2) return INF;
	ll res=0;
	out[path[0]]=c1; res+=C[path[0]][c1];
	out[path[1]]=c2; res+=C[path[1]][c2];
	for (int i=2; i<n; i++){
		swap(c1, c2);
		c2=3-c1-c2;
		out[path[i]]=c2; res+=C[path[i]][c2];
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int j=0; j<3; j++) for (int i=1; i<=n; i++) cin>>C[i][j];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++) if (G[i].size()>2) kill(-1);
	for (int i=1; i<=n && path.empty(); i++) if (G[i].size()==1) path.pb(i);
	dfs(path.back(), 0);
	
	int c1=0, c2=0;
	ll ans=INF;
	for (int i=0; i<3; i++) for (int j=0; j<3; j++){
		ll tmp=cost(i, j);
		if (tmp<ans){
			ans=tmp;
			c1=i;
			c2=j;
		}
	}
	cout<<cost(c1, c2)<<'\n';
	for (int i=1; i<=n; i++) cout<<out[i]+1<<" \n"[i==n];
		
	return 0;
}