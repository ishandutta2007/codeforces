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
const int mod=998244353;
const int MAXN=(1<<19); // TODO

int n, m, k, u, v, x, y, t, a, b;
ll f[MAXN], ans[MAXN];
ll F[MAXN], I[MAXN], inv[MAXN], invps[MAXN];
ll A[MAXN], B[MAXN];
int rev[MAXN];

inline void fix(ll &x){
	if (x<0) x+=mod;
	if (x>=mod) x-=mod;
}
ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(int n, int r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}

void NTT(ll* F, int n, bool inv){
	int lg=ceil(log2(n));
	n=1<<lg;
	//debug2(n, lg)
	for (int i=0; i<n; i++) rev[i]=(rev[i>>1]>>1) | ((i&1)<<(lg-1));
	for (int i=0; i<n; i++) if (i<rev[i]) swap(F[i], F[rev[i]]);
	for (int len=1; len<n; len<<=1){
		ll wn=powmod(3, (mod-1)/(2*len));
		if (inv) wn=powmod(wn, mod-2);
		for (int i=0; i<n; i+=2*len){
			ll w=1;
			for (int j=i; j<i+len; j++){
				ll x=(F[j] + F[j+len]*w)%mod;
				ll y=(F[j] - F[j+len]*w)%mod;
				F[j]=x;
				F[j+len]=y;
				w=w*wn%mod;
			}
		}
	}
	if (inv){
		ll invn=powmod(n, mod-2);
		for (int i=0; i<n; i++) F[i]=F[i]*invn%mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod, inv[i]=I[i]*F[i-1]%mod;
	for (int i=1; i<MAXN; i++) invps[i]=(invps[i-1]+inv[i])%mod;
	
//	debug(nCr(5, 2))
	
	cin>>n;
	m=(n-1)/2;
	
	for (int i=1; i<=m+1; i++) f[i]=F[i-1];
	for (int i=m+2; i<=n; i++){
		ll sum=0;
//		for (int j=m+1; j<=i-1; j++) sum+=inv[j];
		sum=invps[i-1]-invps[m]%mod;
		sum%=mod;
		f[i]=(1-sum)*F[i-1]%mod;
		fix(f[i]);
		// TODO
//		debug2(i, f[i])
	}
	
	for (int i=2; i<=m+1; i++) A[i]=f[n-i+1]*F[i-2]%mod*I[n-i]%mod;
	for (int i=0; i<=n; i++) B[n-i]=I[i];
	
	NTT(A, MAXN, 0);
	NTT(B, MAXN, 0);
	for (int i=0; i<MAXN; i++) A[i]=A[i]*B[i]%mod;
	NTT(A, MAXN, 1);
	
//	for (int i=0; i<=10; i++) cerr<<A[i]<<" \n"[i==10];
	
	for (int k=2; k<=m+1; k++){
		/*
		ll res=0;
		for (int i=0; i<=m-k+1; i++){
			ll val=F[k+i-2]*f[n-k-i+1]%mod*nCr(n-k, i)%mod*(k-1)%mod;
			cerr<<"k="<<k<<" i="<<i<<"    val="<<val<<"\n";
			res=(res+val)%mod;
		}
		fix(res);
		ans[k]=res;
		*/
		ll res=A[n+k];
		fix(res);
		res=res*F[n-k]%mod;
		res=res*(k-1)%mod;
		ans[k]=res;
	}
	ans[1]=ans[2];
	for (int i=1; i<=n; i++) cout<<ans[i]<<" \n"[i==n];
	
	
	return 0;
}