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
const int MAXN = 300010, SGM=26;

int n, m, k, u, v, x, y, t, a, b;
int TR[MAXN][SGM], ts;
int A[MAXN], cnt[MAXN], ted;
int stt[MAXN], fnt[MAXN], ras[MAXN], sz[MAXN], timer=1;
int ans[MAXN];
vector<int> G[MAXN];

int dfs1(int node, int par){
	ras[timer]=node;
	stt[node]=timer++;
	if (!TR[A[par]][A[node]]) TR[A[par]][A[node]]=++ts;
	A[node]=TR[A[par]][A[node]];
	for (int v:G[node]) if (v!=par) sz[node]+=dfs1(v, node);
	fnt[node]=timer;
	return ++sz[node];
}

void add(int x){ ted+=(cnt[x]++==0);}
void rem(int x){ ted-=(--cnt[x]==0);}

void dfs2(int node, int par){
	int big=0;
	for (int v:G[node]) if (v!=par && sz[v]>sz[big]) big=v;
	for (int v:G[node]) if (v!=par && v!=big){
		dfs2(v, node);
		for (int i=stt[v]; i<fnt[v]; i++) rem(A[ras[i]]);
	}
	if (big) dfs2(big, node);
	for (int v:G[node]) if (v!=par && v!=big){
		for (int i=stt[v]; i<fnt[v]; i++) add(A[ras[i]]);
	}
	add(A[node]);
	ans[node]+=ted;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>ans[i];
	for (int i=1; i<=n; i++){
		char ch;
		cin>>ch;
		A[i]=ch-'a';
	}
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	
	int ans1=-1, ans2=0;
	for (int i=1; i<=n; i++){
		if (ans[i]>ans1) ans1=ans[i], ans2=0;
		if (ans[i]==ans1) ans2++;
	}
	cout<<ans1<<'\n'<<ans2<<'\n';
	
	return 0;
}