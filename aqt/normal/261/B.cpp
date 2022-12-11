
// Problem : B. Maxim and Restaurant
// Contest : Codeforces - Codeforces Round #160 (Div. 1)
// URL : https://codeforces.com/contest/261/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, L;
long double dp[55][55][55][55];
int arr[55];
long double fact[55];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	fact[0] = 1;
	int S = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		fact[i] = fact[i-1] * i;
		S += arr[i];
	}
	cin >> L;
	if(S <= L){
		cout << N << "\n";
		return 0;
	}
	long double ans = 0;
	for(int sp = 1; sp<=N; sp++){
		dp[sp][0][0][0] = 1;
		for(int i = 0; i<N; i++){
			for(int j = 0; j<=L; j++){
				for(int k = 0; k<=i; k++){
					if(i+1 != sp && j+arr[i+1] <= L){
						dp[sp][i+1][j+arr[i+1]][k+1] += dp[sp][i][j][k];
					}	
					dp[sp][i+1][j][k] += dp[sp][i][j][k];
				}
			}
		}
		for(int j = 0; j<=L; j++){
			if(j+arr[sp] > L){
				for(int k = 0; k<=N; k++){
					//cout << dp[sp][N][j][k] << " " << fact[k] << " " << fact[N-k-1] << "\n";
					ans += 1LL * k * dp[sp][N][j][k] * fact[k] * fact[N-k-1];
					//cout << ans << "\n";
				}
			}
		}
	}
	cout << setprecision(10) << " " << ans/fact[N] << "\n";
}