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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll F[MAXN], I[MAXN], dp[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(ll n, ll r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}
ll Get(ll y, ll x){ // nCr(x, x) + nCr(x+1, x) + ... + nCr(y, x)
	return nCr(y+1, x+1);
}

void Solve(){
	cin>>n>>k;
	ans=2;
	for (int t=2; t<=n; t++){
		ll sum=0;
		int ii=n-1-k*(t-1);
		if (ii<0) continue ;
		
		for (int i=0; i<=n-1-k*(t-1); i++){
			ll val=nCr(n-i-1-(k-1)*(t-1), t-1)%mod;
			sum=(sum + val)%mod;
		}
		
//		debug2(t, sum)
		sum=Get(n-1-(k-1)*(t-1), t-1)-Get(n-1-(k-1)*(t-1)-ii-1, t-1);
//		debug(sum)
		
		sum%=mod;
		
		ans=(ans + sum*powmod(nCr(n, t), mod-2))%mod;
	}
	if (ans<0) ans+=mod;
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
3 2

*/