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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=998244353;
const int MAXN=3010, LOG=20;

ll n, m, k, u, v, x, y, t, G, B, EG, EB;
ll A[200010], W[200010], inv[MAXN*2];
ll dp[MAXN][MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++){
		cin>>W[i];
		G+=(A[i]==1)*W[i];
		B+=(A[i]==0)*W[i];
	}
	for (int i=0; i<2*MAXN; i++) inv[i]=powmod(G+B+i-MAXN, mod-2);
	dp[0][0]=1;
	for (int i=0; i<=m; i++) for (int j=0; i+j<=m; j++){
		if (i) dp[i][j]=(dp[i][j] + (G+i-1)*inv[i-j-1+MAXN]%mod*dp[i-1][j])%mod;
		if (j) dp[i][j]=(dp[i][j] + (B-j+1)*inv[i-j+1+MAXN]%mod*dp[i][j-1])%mod;
	}
	for (int i=0; i<=m; i++) EG=(EG + i*dp[i][m-i])%mod;
	for (int i=0; i<=m; i++) EB=(EB + i*dp[m-i][i])%mod;
	//debug((EG+EB)%mod)
	for (int i=1; i<=n; i++){
		if (A[i]) cout<<(W[i] + W[i]*powmod(G, mod-2)%mod*EG)%mod<<'\n';
		else cout<<(W[i] - W[i]*powmod(B, mod-2)%mod*EB%mod+mod)%mod<<'\n';
	}
	
	return 0;
}