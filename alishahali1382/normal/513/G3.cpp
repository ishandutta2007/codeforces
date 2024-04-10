#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast,unroll-loops,fast-math")
using namespace std;

const int MAXN = 102, K=900;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
short F1[MAXN][MAXN][2*MAXN];
short F2[MAXN][MAXN][2*MAXN];
short F3[MAXN][MAXN][2*MAXN];
double dp[2][MAXN][MAXN];

int C(int x){
	return x*(x+1)/2;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	k=min(k, K);
	for (int i=0; i<n; i++) cin>>A[i];
	
	for (int l=0; l<n; l++) for (int r=l; r<n; r++){
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++){
			bool ii=(l<=i && i<=r);
			bool jj=(l<=j && j<=r);
			if (ii && !jj) F1[i][j][l+r]++;
			if (!ii && jj) F2[i][j][l+r]++;
			if (ii && jj) F3[i][j][l+r]++;
		}		
	}
	int prev=0, curr=1;
	for (int i=0; i<n; i++) for (int j=0; j<i; j++) dp[0][i][j]=1;
	for (int x=1; x<=k; x++){
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++){
			dp[curr][i][j]=(C(i) + C(j-i-1) + C(n-j-1))*dp[prev][i][j];
			for (int cent=i; cent<n+i; cent++) dp[curr][i][j]+=F1[i][j][cent]*dp[prev][cent-i][j];
			for (int cent=j; cent<n+j; cent++) dp[curr][i][j]+=F2[i][j][cent]*dp[prev][i][cent-j];
			for (int cent=j; cent<n+i; cent++) dp[curr][i][j]+=F3[i][j][cent]*dp[prev][cent-i][cent-j];
			
			dp[curr][i][j]/=C(n);
			dp[curr][j][i]=1.-dp[curr][i][j];
		}
		swap(prev, curr);
	}
	double ans=0;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (A[i]<A[j]) ans+=dp[prev][i][j];
	cout<<setprecision(12)<<fixed<<ans<<'\n';
	
	return 0;
}