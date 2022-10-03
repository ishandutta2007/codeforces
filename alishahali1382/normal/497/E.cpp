#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops,no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
const int K=30, LOG=61, mod=1000000007;

struct Matrix{
	ll M[K+1][K+1];
	Matrix(){
		memset(M, 0, sizeof(M));
	}
	ll* operator [](int i){
		return M[i];
	}
};

Matrix operator *(Matrix A, Matrix B){
	Matrix C;
	for (int k=0; k<=K; k++) for (int i=0; i<=K; i++) for (int j=0; j<=K; j++)
		C[i][j]=(C[i][j] + A[i][k]*B[k][j])%mod;
	return C;
}

ll n, m, k, u, v, x, y, t, a, b, ans;
Matrix T[LOG][K], Ans;

int Build(ll n, int lg){
	if (!n) return 0;
	int sum=Build(n/k, lg+1);
	n%=k;
	for (int i=0; i<n; i++) Ans=Ans*T[lg][(sum+i)%k];
	sum=(sum+n)%mod;
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int j=0; j<k; j++){
		for (int i=0; i<k; i++) T[0][j][i][i]=T[0][j][i][j]=1;
		T[0][j][K][K]=T[0][j][K][j]=1;
	}
	for (int lg=1; lg<LOG; lg++){
		for (int i=0; i<=K; i++) T[lg][0][i][i]=1;
		for (int i=0; i<k; i++) T[lg][0]=T[lg][0]*T[lg-1][i];
		for (int x=1; x<k; x++){
			for (int i=0; i<k; i++) for (int j=0; j<k; j++) 
				T[lg][x][(i+x)%k][(j+x)%k]=T[lg][0][i][j];
			for (int i=0; i<k; i++){
				T[lg][x][(i+x)%k][K]=T[lg][0][i][K];
				T[lg][x][K][(i+x)%k]=T[lg][0][K][i];
			}
			T[lg][x][K][K]=T[lg][0][K][K];
		}
	}
	
	Ans[0][K]=1;
	Build(n, 0);
	
	for (int i=0; i<=K; i++) ans+=Ans[0][i];
	ans%=mod;
	cout<<ans<<'\n';
	
	return 0;
}