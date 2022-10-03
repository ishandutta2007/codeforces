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
const int N = 20, MAXN=N+1;
int mod;

struct Matrix{
	ll M[MAXN][MAXN];
	Matrix(){
		memset(M, 0, sizeof(M));
	}
	ll* operator [](int i){
		return M[i];
	}
} T;

Matrix operator *(Matrix &A, Matrix &B){
	Matrix C;
	for (int k=0; k<MAXN; k++) for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) C[i][j]=(C[i][j] + A[i][k]*B[k][j])%mod;
	return C;
}

Matrix operator ^(Matrix A, ll tav){
	Matrix Ans;
	for (int i=0; i<MAXN; i++) Ans[i][i]=1;
	for (; tav; tav>>=1, A=A*A) if (tav&1) Ans=Ans*A;
	return Ans;
}

ll n, m, k, u, v, x, y, t, a, b, ans;
ll E0[1<<N];
ll B1[MAXN];
ll Comb[MAXN][MAXN];
int dp[N+1][1<<N];

inline int _mod(int x){
	if (x>=mod) x-=mod;
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>t>>mod;
	for (int i=0; i<(1<<n); i++) cin>>E0[i];
	if (!t){
		for (int i=0; i<(1<<n); i++) cout<<E0[i]<<'\n';
		return 0;
	}
	for (int i=0; i<=n; i++) cin>>B1[i];
	
	for (int i=0; i<MAXN; i++){
		Comb[i][0]=Comb[i][i]=1;
		for (int j=1; j<i; j++) Comb[i][j]=(Comb[i-1][j-1] + Comb[i-1][j])%mod;
	}
	
	for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) for (int k=0; k<=n; k++){
		if (i+k-j<0 || i+k-j>n || j+k>n) continue ;
		T[i+k-j][i]=(T[i+k-j][i] + B1[j+k]*(Comb[i][j]*Comb[n-i][k]%mod))%mod;
	}
	
	T=T^(t-1);
	Matrix B;
	for (int i=0; i<=n; i++) B[0][i]=B1[i];
	B=B*T;
	
	for (int i=0; i<(1<<n); i++) dp[0][i]=E0[i]%mod;
	for (int i=0; i<n; i++) for (int j=i+1; j; j--) for (int mask=0; mask<(1<<n); mask++) dp[j][mask]=_mod(dp[j][mask] + dp[j-1][mask^(1<<i)]);
	for (int mask=0; mask<(1<<n); mask++){
		ll res=0;
		for (int i=0; i<=n; i++) res=(res + B[0][i]*dp[i][mask])%mod;
		cout<<res<<'\n';
	}
	
	return 0;
}