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

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN*2], L[MAXN];
bool bad[MAXN];
int stt[MAXN], fnt[MAXN], timer=1;
int par[MAXN][LOG];
ll dp[MAXN][2];
vector<int> G[MAXN];

void dfs(int node, int p){
	stt[node]=timer++;
	par[node][0]=p;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (int v:G[node]) if (v!=p) dfs(v, node);
	fnt[node]=timer;
}

bool is_par(int u, int v){
	return stt[u]<=stt[v] && fnt[v]<=fnt[u];
}

int Lca(int x, int y){
	if (stt[x]>stt[y]) swap(x, y);
	if (fnt[y]<=fnt[x]) return x;
	for (int i=LOG-1; ~i; i--) if (!is_par(par[x][i], y)) x=par[x][i];
	return par[x][0];
}

void dfs2(int node){
	for (int v:G[node]) dfs2(v);
	if (bad[node]){
		dp[node][0]=inf;
		dp[node][1]=0;
		for (int v:G[node]) dp[node][1]+=min(dp[v][0], dp[v][1]+1);
	}
	else{
		ll s1=0, s2=0;
		for (int v:G[node]){
			s1+=dp[v][0];
			s2+=min(dp[v][0], dp[v][1]);
		}
		dp[node][0]=min(s1, s2+1);
		dp[node][1]=dp[node][0];
		for (int v:G[node]) dp[node][1]=min(dp[node][1], s1-dp[v][0]+dp[v][1]);
	}
}

void solve(){
	cin>>k;
	for (int i=1; i<=k; i++) cin>>A[i], bad[A[i]]=1;
	for (int i=1; i<=k; i++) if (bad[par[A[i]][0]]){
		for (int j=1; j<=k; j++) bad[A[j]]=0;
		cout<<"-1\n";
		return ;
	}
	A[0]=1;
	int N=k+1;
	sort(A, A+N, [](int i, int j){
		return stt[i]<stt[j];
	});
	for (int i=1; i<=k; i++)  A[N++]=Lca(A[i], A[i-1]);
	sort(A, A+N, [](int i, int j){
		return stt[i]<stt[j];
	});
	N=unique(A, A+N)-A;
	for (int i=0; i<N; i++) G[A[i]].clear();
	//cerr<<"all : ";for (int i=0; i<N; i++) cerr<<A[i]<<" \n"[i==N-1];
	
	for (int i=1; i<N; i++){
		for (L[i]=i-1; L[i] && fnt[A[L[i]]]<fnt[A[i]]; L[i]=L[L[i]]);
		G[A[L[i]]].pb(A[i]);
	}
	dfs2(1);
	cout<<min(dp[1][0], dp[1][1])<<'\n';
	for (int i=0; i<N; i++) bad[A[i]]=0;
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
	fnt[0]=n+1;
	for (int i=1; i<=n; i++) G[i].clear();
	
	cin>>m;
	while (m--) solve();
	
	return 0;
}
/*
4
1 3
2 3
4 3
1
3 1 2 4



*/