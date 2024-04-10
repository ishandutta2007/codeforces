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
const int MAXN = 1000010, LOG=20;
 
ll n, m, k, u, v, x, y, t, a, b, ans, ans2;
ll F[MAXN];
ll I[MAXN];
 
ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}
 
ll inv(ll x){ return powmod(x, mod-2);}
 
ll C(ll n, ll r){
	if (r<0 || r>n) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	cin>>n;
	for (int i=1; i<=n; i++){
		ll tmp=powmod(3, mod-1-i);
		ll sum=powmod(powmod(3, mod-n-1)-tmp, n)-powmod(-tmp, n);
		sum=sum*C(n, i)%mod;
		if ((n-i)&1) sum=-sum;
		ans+=sum;
	}
	ans%=mod;
	ans=ans*powmod(3, n*n+1)%mod;
	
	for (int i=1; i<=n; i++){
		if (i&1) ans2+=C(n, i)*powmod(3, 1ll*n*(n-i)+i)%mod;
		else ans2-=C(n, i)*powmod(3, 1ll*n*(n-i)+i)%mod;
	}
	
	ll out=(2*ans2-ans)%mod;
	if (out<0) out+=mod;
	cout<<out<<'\n';
	
	return 0;
}