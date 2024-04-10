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
const int mod = 998244353;
const int MAXN = 2010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, P;
ll C[MAXN][MAXN];
ll dp[MAXN];
ll ans[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll inv(ll x, ll i=1){ return powmod(x, mod-1-i);}

ll C2(ll x){
	return (x*(x-1)/2)%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>a>>b;
	P=a*inv(b)%mod;
	
	C[0][0]=1;
	for (int i=1; i<=n; i++){
		C[i][0]=1;
		for (int j=1; j<=i; j++) C[i][j]=(powmod(P, j)*C[i-1][j] + powmod(1-P, i-j)*C[i-1][j-1])%mod;
	}
	
	dp[1]=1;
	for (int i=2; i<=n; i++){
		for (int j=1; j<i; j++) dp[i]+=C[i][j]*dp[j]%mod;
		dp[i]=(1-dp[i]+mod)%mod;
	}
	
	for (int i=2; i<=n; i++){
		for (int j=1; j<i; j++) ans[i]+=(C[i][j]*dp[j]%mod)*(ans[j]+ans[i-j]-C2(i-j))%mod;
		ans[i]+=C2(i);
		ans[i]%=mod;
		ans[i]=ans[i]*inv(1-dp[i])%mod;
	}
	ans[n]=(ans[n]+mod)%mod;
	cout<<ans[n]<<'\n';
	
	return 0;
}