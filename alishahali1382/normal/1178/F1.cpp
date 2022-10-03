#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int mod = 998244353;
const int MAXN = 510, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
ll C[MAXN];
ll dp[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=m; i++) cin>>C[i];
	for (int i=0; i<=n+2; i++) for (int j=0; j<=n+2; j++) dp[i][j]=1;
	for (int l=n; l; l--) for (int r=l; r<=n; r++){
		int pos=l;
		for (int i=l; i<=r; i++) if (C[i]<C[pos]) pos=i;
		ll L=0, R=0;
		for (int i=l; i<=pos; i++) L=(L+dp[l][i-1]*dp[i][pos-1])%mod;
		for (int i=pos; i<=r; i++) R=(R+dp[pos+1][i]*dp[i+1][r])%mod;
		dp[l][r]=L*R%mod;/*
		debug2(l, r)
		debug2(L, R)*/
	}/*
	debug(C[2])
	debug(dp[1][1])
	debug(dp[2][2])
	debug(dp[3][3])
	debug(dp[1][2])
	debug(dp[2][3])
	debug(dp[1][3])*/
	cout<<dp[1][n]<<'\n';
	
	return 0;
}