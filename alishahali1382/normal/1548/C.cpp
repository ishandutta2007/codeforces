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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=3000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
ll F[MAXN], I[MAXN], ans[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(ll n, ll r){
	if (r<0 || r>n) return 0;
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
	
	cin>>n>>m;
	
	ll ans1=0, ans2=0, ans3=0, inv3=powmod(3, mod-2);
	for (int i=1; i<=n; i++){
		ans1=(ans1+3*i-2)%mod;
		ans2=(ans2+3*i-1)%mod;
		ans3=(ans3+3*i-0)%mod;
	}
	ans[1]=ans3;
//	debug(ans1)
//	debug(ans2)
//	debug(ans3)
	for (int x=2; x<=3*n; x++){
//		if (x==2){
//			debug(nCr(3*n+1, x+1))
//			debug(nCr(3*n+1, x+1)-ans2-2*ans1)
//		}
		ll res1=(nCr(3*n+1, x+1)-ans2-2*ans1)%mod*inv3%mod;
		ll res2=(ans1+res1)%mod;
		ll res3=(ans2+res2)%mod;
		ans1=res1;
		ans2=res2;
		ans3=res3;
//		cerr<<x<<": "<<res1<<" "<<res2<<" "<<res3<<"\n";
		ans[x]=ans3;
	}
	
	while (m--){
		cin>>x;
		if (ans[x]<0) ans[x]+=mod;
		cout<<ans[x]<<"\n";
	}
	
	
	return 0;
}