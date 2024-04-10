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
#define get(x, y) (((x)>>(y))&1)

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 128, LOG=7;

struct MAT{
	int A[MAXN][MAXN];
	MAT(){ memset(A, 0, sizeof(A));}
	int* operator [](int i){
		return A[i];
	}
	void ID(){
		for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) A[i][j]=(i==j);
	}
};

MAT operator *(MAT &A, MAT &B){
	MAT C;
	for (int i=0; i<MAXN; i++) for (int k=0; k<MAXN; k++) for (int j=0; j<MAXN; j++) C[i][j]=(C[i][j]+1ll*A[i][k]*B[k][j])%mod;
	return C;
}

MAT operator ^(MAT &M, int tav){
	MAT A;
	A.ID();
	for (MAT B=M; tav; tav>>=1, B=B*B) if (tav&1) A=A*B;
	return A;
}

int n, m, k, u, v, x, y, t, a, b;
int W[8];
ll dp[MAXN];
ll tmp[MAXN];

void MUL(MAT &T){
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) tmp[j]=(tmp[j]+dp[i]*T[i][j])%mod;
	for (int i=0; i<MAXN; i++) dp[i]=tmp[i], tmp[i]=0;
}

void TOF(MAT &M, int tav){
	for (; tav; tav>>=1, M=M*M) if (tav&1) MUL(M);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	dp[0]=1;
	for (int len=1; len<=7; len++){
		MAT T;
		for (int i=127; i>=(1<<(len-1)); i--){
			dp[i]=dp[i-(1<<(len-1))];
			dp[i-(1<<(len-1))]=0;
		}
		
		for (int mask1=0; mask1<(1<<len); mask1++) for (int mask2=(1<<len)+1; mask2<(1<<(len+1)); mask2+=2) for (int mask3=0; mask3<(1<<len); mask3++){
			bool f=1;
			for (int i=0; i<len && f; i++) if (get(mask1&mask3, i) && get(mask2, i) && get(mask2, i+1)) f=0;
			if (f) T[mask1][mask3]++;
		}
		cin>>W[len];
		if (!W[len]) continue ;
		//T=T^W[len];
		TOF(T, W[len]);
		
		/*
		for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) tmp[j]=(tmp[j]+dp[i]*T[i][j])%mod;
		for (int i=0; i<MAXN; i++) dp[i]=tmp[i], tmp[i]=0;
		*/
	}
	cout<<dp[127]<<'\n';
	
	
	return 0;
}