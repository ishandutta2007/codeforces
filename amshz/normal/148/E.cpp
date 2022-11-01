# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
const int xk = 1e4+10;

int sm[xn][xn], a[xn][xn], t[xn], bm[xn][xk], dp[xn][xk];

int fn1(int a){
	if (a < 0) return 105;
	return a;
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> t[i];
		int s = 0;
		for (int j=0; j<t[i]; j++) cin >> a[i][j], s += a[i][j], sm[i][j] = s;
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<=t[i]; j++){
			for (int k=0; k<=j; k++){
				bm[i][j] = max(bm[i][j], sm[i][fn1(k-1)]+sm[i][t[i]-1]-sm[i][fn1(t[i]-j+k-1)]);
			}
		}
	}
	for (int j=0; j<=t[0]; j++) dp[0][j] = bm[0][j];
	for (int i=1; i<n; i++){
		for (int j=0; j<=m; j++){
			for (int k=0; k<=t[i]; k++) 
				if (i-1 >= 0 and j-k >= 0) dp[i][j] = max(dp[i][j], bm[i][k]+dp[i-1][j-k]);
		}
	}
	cout << dp[n-1][m] << endl;
}