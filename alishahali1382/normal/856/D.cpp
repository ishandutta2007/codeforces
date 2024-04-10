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
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int stt[MAXN], fnt[MAXN], ras[MAXN], timer=1;
int par[MAXN], head[MAXN], h[MAXN], sz[MAXN];
int dp[MAXN], sum[MAXN];
ll fen[MAXN];
vector<int> G[MAXN];
vector<piii> vec[MAXN];

void dfs1(int node, int hd){
	ras[stt[node]=timer++]=node;
	head[node]=hd;
	int big=0;
	for (int v:G[node]) if (sz[v]>sz[big]) big=v;
	if (big) dfs1(big, hd);
	for (int v:G[node]) if (v!=big) dfs1(v, v);
	fnt[node]=timer;
}

inline int Lca(int x, int y){
	while (head[x]!=head[y]){
		if (h[head[x]]<h[head[y]]) swap(x, y);
		x=par[head[x]];
	}
	if (h[x]>h[y]) swap(x, y);
	return x;
}

inline void add(int pos, int x){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=x;
}
inline int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

void dfs2(int node){
	for (int v:G[node]){
		dfs2(v);
		sum[node]+=dp[v];
	}
	dp[node]=sum[node];
	for (piii p:vec[node]){
		int tmp=get(stt[p.first.first])+get(stt[p.first.second]);
		tmp+=sum[node]+p.second;
		dp[node]=max(dp[node], tmp);
	}
	add(stt[node], sum[node]-dp[node]);
	add(fnt[node], dp[node]-sum[node]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=2; i<=n; i++) cin>>par[i], h[i]=h[par[i]]+1, G[par[i]].pb(i);
	for (int i=n; i>1; i--) sz[par[i]]+=++sz[i];
	dfs1(1, 1);
	while (m--){
		cin>>u>>v>>x;
		vec[Lca(u, v)].pb({{u, v}, x});
	}
	dfs2(1);
	cout<<dp[1]<<'\n';
	
	return 0;
}