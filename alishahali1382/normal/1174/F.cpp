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
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, d, dd, ans;
int sz[MAXN];
bool dead[MAXN];
vector<int> G[MAXN];

int dfs1(int node, int par){
	sz[node]=1;
	for (int v:G[node]) if (!dead[v] && v!=par) sz[node]+=dfs1(v, node);
	return sz[node];
}

pii Centroid(int node, int par, int n, int h=0){
	for (int v:G[node]) if (v!=par && !dead[v] && sz[v]*2>n) return Centroid(v, node, n, h+1);
	return {node, h};
}

int ask1(int u){
	cout<<"d "<<u<<endl;
	cin>>ans;
	if (!ans){
		cout<<"! "<<u<<endl;
		exit(0);
	}
	return ans;
}

int ask2(int u){
	cout<<"s "<<u<<endl;
	cin>>ans;
	return ans;
}

void solve(int root){
	if (d==0){
		cout<<"! "<<root<<endl;
		exit(0);
	}
	pii p=Centroid(root, root, dfs1(root, root));
	int c=p.first, h=p.second;
	dead[c]=1;
	int dd=ask1(c);
	if (h+dd==d){
		d=dd-1;
		solve(ask2(c));
		return ;
	}
	solve(root);
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
	d=ask1(1);
	solve(1);
	
	return 0;
}