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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN];
int mark[MAXN], cycle[MAXN], to[MAXN];
int par[MAXN], dp[MAXN];
vector<int> vec[MAXN];

int getpar(int x){ return (par[x]==x?x:par[x]=getpar(par[x]));}
int dfs(int v){
	if (dp[v]!=-1) return dp[v];
	return dp[v]=dfs(A[v])+1;
}

int Solve(){
	ans=0;
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		to[i]=mark[i]=cycle[i]=0;
		B[i]=0;
		dp[i]=-1;
		vec[i].clear();
		par[i]=i;
	}
	for (int i=1; i<=n; i++) par[getpar(i)]=getpar(A[i]);
	for (int i=1; i<=n; i++) vec[getpar(i)].pb(i);
	
	for (int i=1; i<=n; i++) if (SZ(vec[i])){
		int v=vec[i][0];
		while (cycle[v]<2){
			cycle[v]++;
//			if (cycle[v]==2) dp[v]=0;
			v=A[v];
		}
		/*
		int mx=0, src=-1;
		for (int v:vec[i]) mx=max(mx, dfs(v));
		if (!mx){
			for (int v:vec[i]) B[v]=A[v];
			continue ;
		}
		
		for (int v:vec[i]) if (dp[v]==mx) src=v;
		
		v=src;
		while (!B[A[v]]){
			B[v]=A[v];
			v=A[v];
		}
		*/
	}
	for (int i=1; i<=n; i++) if (cycle[i]!=2 && !mark[A[i]]){
		B[i]=A[i];
		mark[B[i]]=1;
		ans++;
	}
	for (int i=1; i<=n; i++) if (!mark[A[i]]){
		B[i]=A[i];
		mark[B[i]]=1;
		ans++;
	}
	vector<int> shit;
	for (int i=1; i<=n; i++) if (!mark[i]){
		int v=i;
		while (B[v] && B[v]!=i) v=B[v];
		if (B[v]==i) continue ;
		to[i]=v;
		shit.pb(i);
	}
	if (SZ(shit)){
		for (int i=0; i<SZ(shit)-1; i++) B[to[shit[i]]]=shit[i+1];
		B[to[shit.back()]]=shit[0];
	}
	cout<<ans<<"\n";
	for (int i=1; i<=n; i++) cout<<B[i]<<" \n"[i==n];
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}