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
const int MAXN=200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, root;
int h[MAXN], mx[MAXN][2];
pii ans, out1, out2;
vector<int> G[MAXN];

void dfs(int node, int par){
	h[node]=h[par]+1;
	mx[node][0]=node;
	mx[node][1]=0;
	for (int v:G[node]) if (v!=par){
		dfs(v, node);
		if (h[mx[v][0]]>h[mx[node][1]]) mx[node][1]=mx[v][0];
		if (h[mx[node][0]]<h[mx[node][1]]) swap(mx[node][0], mx[node][1]);
	}
	if (G[node].size()>=3){
		pii shit={h[node], h[mx[node][0]]+h[mx[node][1]]};
		if (shit<ans) return ;
		ans=shit;
		root=node;
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
	dfs(1, 0);
	out1.first=mx[root][0];
	out2.first=mx[root][1];
	ans={0, 0};
	dfs(root, 0);
	out1.second=mx[root][0];
	out2.second=mx[root][1];
	cout<<out1.first<<' '<<out1.second<<"\n";
	cout<<out2.first<<' '<<out2.second<<"\n";
	
	return 0;
}