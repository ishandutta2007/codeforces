#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
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
const int mod = 998244353;
const int N = 1<<16, K=1<<15, LG=16;
typedef array<ll, K> Poly;
typedef pair<Poly, Poly> Data;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[N], B[N];
int rev[N];
Poly dp[256];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

void NTT(ll* F, bool inv){
	for (int i=0; i<N; i++) if (i<rev[i]) swap(F[i], F[rev[i]]);
	for (int len=1; len<N; len<<=1){
		ll wn=powmod(3, (mod-1)/(2*len));
		if (inv) wn=powmod(wn, mod-2);
		for (int i=0; i<N; i+=2*len){
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
		ll invn=powmod(N, mod-2);
		for (int i=0; i<N; i++) F[i]=F[i]*invn%mod;
	}
}

Poly operator *(Poly &x, Poly &y){
	for (int i=0; i<K; i++) A[i]=x[i], B[i]=y[i];
	for (int i=K; i<N; i++) A[i]=B[i]=0;
	NTT(A, 0);
	NTT(B, 0);
	for (int i=0; i<N; i++) A[i]=A[i]*B[i]%mod;
	NTT(A, 1);
	Poly z;
	for (int i=0; i<K; i++) z[i]=A[i];
	return z;
}

Data operator *(Data X, Data Y){ // x+y  -> x+y+1
	Poly aa=X.first, a=X.second;
	Poly bb=Y.first, b=Y.second;

	Poly ab=a*b, aabb=aa*bb;
	Poly cc=ab;
	for (int i=1; i<K; i++) cc[i]=(cc[i]+aabb[i-1])%mod;

	Poly aaa;
	aaa[0]=1;
	for (int i=1; i<K; i++) aaa[i]=(a[i]+a[i-1]+aa[i-1])%mod;
	Poly aaab=aaa*b, abb=a*bb;
	Poly c=aaab;
	for (int i=1; i<K; i++) c[i]=(c[i]+abb[i-1])%mod;

	return {cc, c};
}

Data Get(int n){
	if (n<50) return {dp[n-1], dp[n]};
	if (n&1){
		int k=n>>1;
		Data X=Get(k);
		return X*X;
	}
	Data D=Get(n-1);
	Poly Z;
	Z[0]=1;
	for (int i=1; i<K; i++) Z[i]=(D.second[i] + D.second[i-1] + D.first[i-1])%mod;

	return {D.second, Z};
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<N; i++) rev[i]=(rev[i>>1]>>1) | ((i&1)<<(LG-1));
	
	dp[0][0]=dp[1][0]=dp[1][1]=1;
	for (int i=2; i<256; i++){
		dp[i][0]=1;
		for (int j=1; j<K; j++) dp[i][j]=(dp[i-1][j] + dp[i-1][j-1] + dp[i-2][j-1])%mod;
	}
	
	cin>>n>>k;
	Poly Ans=Get(n).second;
	for (int i=1; i<=k; i++) cout<<(Ans[i]+mod)%mod<<' ';

	return 0;
}