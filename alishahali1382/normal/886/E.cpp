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
const int MAXN = 1000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll F[MAXN], I[MAXN];
ll dp[MAXN], ps[MAXN];

ll powmod(ll a, ll b, ll res=1){
	if (!b) return res;
	if (b&1) return powmod(a*a%mod, b>>1, res*a%mod);
	return powmod(a*a%mod, b>>1, res);
}

ll C(ll n, ll r){
	return F[n]*I[r]%mod*I[n-r]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	cin>>n>>k;
	dp[1]=ps[1]=1;
	for (int i=2; i<=n; i++){
		int l=max(1ll, i-k), r=i-1;
		dp[i]=F[i-2]*(ps[r]-ps[l-1])%mod;
		ps[i]=(ps[i-1]+dp[i]*I[i-1])%mod;
	}
	for (int i=1; i<=n; i++) ans=(ans+dp[i]*C(n-1, i-1)%mod*F[n-i])%mod;
	ans=(F[n]-ans)%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	
	return 0;
}