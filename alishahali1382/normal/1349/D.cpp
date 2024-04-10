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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=998244353;
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN], G[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], m+=A[i];
	for (int i=0; i<m; i++){
		ll x=1, y=1;
		if (i) x+=G[i-1]*i%mod*powmod(m, mod-2)%mod;
		y-=i*powmod(m, mod-2)%mod;
		y-=(m-i)*(n-2)%mod*powmod(m*(n-1)%mod, mod-2)%mod;
		G[i]=x*powmod(y, mod-2)%mod;
	}
	for (int i=m-1; ~i; i--) G[i]=(G[i]+G[i+1])%mod;
	for (int i=1; i<=n; i++) ans+=G[A[i]];
	ans-=G[0]*(n-1);
	ans%=mod;
	ans=ans*powmod(n, mod-2)%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	
	return 0;
}