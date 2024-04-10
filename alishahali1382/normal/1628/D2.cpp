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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
ll F[MAXN], I[MAXN], tav2[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(int n, int r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}
ll Solve(int n, int m){
	if (m==0) return 0;
	if (m==n) return n*tav2[n]%mod;
	ll ans=0;
	for (int i=1; i<=m; i++) ans=(ans + i*tav2[i]%mod*nCr(n-i-1, n-m-1))%mod;
	
//	debug2(n-1-1, n-m)
	
	return ans%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	tav2[0]=1;
	for (int i=1; i<MAXN; i++) tav2[i]=tav2[i-1]*2%mod;
	
//	for (int n=1; n<=2000; n++){
//		pd[0][n]=n*tav2[n]%mod;
//		for (int m=1; m<n; m++){
//			pd[n-m][m]=(pd[n-m-1][m]+pd[n-m][m-1])%mod;
//		}
//	}
	int T=1;
	cin>>T;
	while (T--){
		cin>>n>>m>>k;
		ll ans=Solve(n, m);
		
//		debug(ans)
//		debug(pd[n-m][m])
		
		ans=ans*k%mod*powmod(2, mod-1-n)%mod;
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
/*
1
10 8 1

ans: 710937511

1
2 1 10

*/