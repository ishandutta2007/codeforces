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
const ll INF=10000000000000010LL;
const int MAXN=300010, N=18;

ll n, m, k, u, v, x, y, t, a, b;
ll F[MAXN], I[MAXN];
int tmp[N+1], X[N+1], Y[N+1], mod;
int A[N+1][1<<N], B[N+1][1<<N];

inline ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
inline void fix(int &x){
	if (x>=mod) x-=mod;
	if (x<0) x+=mod;
}
inline void SOS(int *A, int inv){
	for (int i=0; i<N; i++) for (int j=0; j<(1<<N); j++)
		if (j&(1<<i)) fix(A[j]+=inv*A[j^(1<<i)]);
//	for (int i=0; i<(1<<N); i++) A[i]%=mod;
}
inline void Mul(int *A, int *B){
	for (int i=0; i<=N; i++) tmp[i]=0;
	for (int i=0; i<=N; i++) for (int j=0; i+j<=N; j++)
		tmp[i+j]=(tmp[i+j] + 1ll*A[i]*B[j])%mod;
	for (int i=0; i<=N; i++) A[i]=tmp[i];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>mod;
	if (n&1) kill(powmod(k, n))
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	for (int i=0; i<(1<<N); i++) A[__builtin_popcount(i)][i]=I[i];
	for (int i=0; i<=N; i++) SOS(A[i], +1);
	for (int i=0; i<(1<<N); i++){
		for (int j=0; j<=N; j++) X[j]=A[j][i], Y[j]=(j==0);
		for (int x=k; x; x>>=1, Mul(X, X)) if (x&1) Mul(Y, X);
		for (int t=0; t<=N; t++) B[t][i]=Y[t];
	}
	for (int i=0; i<=N; i++) SOS(B[i], -1);
	ll ans=B[__builtin_popcount(n)][n]*F[n]%mod;
	debug(ans)
	ans=(powmod(k, n)-ans+mod)%mod;
	cout<<ans<<"\n";
	
	return 0;
}