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
#define SZ(x) ((int)(x.size()))

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=998244353;
const int MAXN=1510, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN][MAXN];
int comp[MAXN], deg[MAXN];
vector<int> vec[MAXN];
vector<ll> dp[MAXN];
pair<int, pii> E[MAXN*MAXN/2];

vector<ll> mul(vector<ll> a, vector<ll> b){
	vector<ll> c(SZ(a) + SZ(b)-1, 0);
	for (int i=1; i<SZ(a); i++) for (int j=1; j<SZ(b); j++)
		c[i+j]=(c[i+j] + a[i]*b[j])%mod;
	return c;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		vec[i]={comp[i]=i};
		dp[i]={0, 1};
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
		cin>>A[i][j];
		if (i<j) E[m++]={A[i][j], {i, j}};
	}
	sort(E, E+m);
	for (int i=0; i<m; i++){
		int u=E[i].second.first, v=E[i].second.second;
		u=comp[u];
		v=comp[v];
		if (u^v){
			for (int x:vec[u]) comp[x]=v, vec[v].pb(x);
			vec[u].clear();
			dp[v]=mul(dp[u], dp[v]);
			dp[u].clear();
			deg[v]+=deg[u];
		}
		deg[v]++;
		if (deg[v]*2==SZ(vec[v])*(SZ(vec[v])-1)) dp[v][1]++;
	}
	for (int i=1; i<=n; i++) cout<<dp[comp[1]][i]<<" \n"[i==n];
	
	return 0;
}