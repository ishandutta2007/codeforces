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

int n, m, k, u, v, x, y, t, a, b;
bool dead[MAXN];
int par[MAXN], sz[MAXN];
vector<int> G[MAXN];
vector<int> vec;

int ask(int u, int v){
	cout<<"? "<<u<<' '<<v<<endl;
	int x;
	cin>>x;
	assert(x!=-1);
	return x;
}

void found(int x){
	cout<<"! "<<x<<endl;
	exit(0);
}

int dfs(int node){
	sz[node]=1;
	vec.pb(node);
	for (int v:G[node]) if (!dead[v] && v!=par[node]) par[v]=node, sz[node]+=dfs(v);
	return sz[node];
}

void Solve(int root){
	memset(par, 0, sizeof(par));
	memset(sz, 0, sizeof(sz));
	vec.clear();
	if (dfs(root)==1) found(root);
	int v=vec.back();
	if (par[v]==root){
		if (sz[root]==2) found(ask(v, root));
		Solve(v);
		return ;
	}
	int a=v, b=par[a], c=par[b];
	int lca=ask(a, c);
	if (lca==a){
		dead[b]=dead[c]=1;
		Solve(a);
		return ;
	}
	if (lca==c){
		dead[a]=dead[b]=1;
		Solve(c);
		return ;
	}
	dead[a]=dead[c]=1;
	Solve(b);
	return ;
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
	Solve(1);
	
	return 0;
}