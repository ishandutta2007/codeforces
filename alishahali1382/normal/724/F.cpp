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
const int MAXN = 1110, LOG=20;

ll n, m, k, d, x, y, t, a, b, mod;
ll dp[MAXN][MAXN][11];
ll F[MAXN];
ll I[MAXN];
ll inv[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll C(ll n, ll r){
	if (r>n || r<0) return 0;
	if (n<MAXN) return (F[n]*I[r]%mod)*I[n-r]%mod;
	ll res=1;
	r=min(r, n-r);
	for (int i=1; i<=r; i++) res=res*((n-i+1)*inv[i]%mod)%mod;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>d>>mod;
	if (n<=2 || d==2) kill(1)
	F[0]=inv[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	for (int i=1; i<MAXN-1; i++) inv[i]=I[i]*F[i-1]%mod;
	
	for (int i=0; i<=n; i++) dp[0][i][0]=dp[1][i][0]=dp[1][i][d-1]=1;
	
	for (int i=2; i<=n; i++) for (int j=1; j<=n; j++) for (int k=1; k<=d; k++){
		dp[i][j][k]=dp[i][j-1][k];
		for (int t=1; t<=k; t++) if (i-t*j>0) dp[i][j][k]+=dp[i-t*j][j-1][k-t] * C(dp[j][n/2][d-1]+t-1, t)%mod;
		dp[i][j][k]%=mod;
	}
	
	ll ans=dp[n][n/2-1][d];
	if (n%2==0) ans=(ans+C(dp[n/2][n/2][d-1]+1, 2))%mod;
	cout<<ans<<'\n';
	
	return 0;
}