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
const int MAXN = 5110, LOG=20;

ll n, s, r, u, v, x, y, t, a, b, ans;
ll F[MAXN], I[MAXN];
ll dp[110];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll C(ll n, ll r){
	if (n<0 || n<r) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

ll count(ll k, ll n){
	if (!k && !n) return 1;
	return C(n+k-1, k-1);
}

ll f(ll n, ll sum, ll lim){
	ll res=0;
	for (int i=0; i<=n && i*lim<=sum; i++){
		ll tmp=count(n, sum-lim*i)*C(n, i)%mod;
		if (i&1) tmp=-tmp;
		res+=tmp;
	}
	return res%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	cin>>n>>s>>r;
	for (int x=r; x<=s; x++) for (int t=1; t<=n && t*x<=s; t++) ans+=C(n, t)*f(n-t, s-t*x, x)%mod;
	ans%=mod;
	//debug2(ans, C(s-r+n-1, n-1))
	ans=ans*powmod(C(s-r+n-1, n-1), mod-2)%mod;
	ans=ans*powmod(n, mod-2)%mod;
	cout<<ans<<'\n';
	
	
	return 0;
}
/*
3 30 10

*/