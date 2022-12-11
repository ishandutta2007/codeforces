
// Problem : E. Array Shrinking
// Contest : Educational Codeforces Round 83 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1312/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[505];
int dp1[505][505];
int dp2[505];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		dp1[i][i] = arr[i];
	}
	for(int len= 1; len<=N; len++){
		for(int l = 1; l<=N-len; l++){
			int r = len+l;
			for(int k = l; k<r; k++){
				if(dp1[l][k] && dp1[l][k] == dp1[k+1][r]){
					dp1[l][r] = dp1[l][k] + 1;
					break;
				}
			}
		}
	}
	for(int i = 1; i<=N; i++){
		dp2[i] = i;
		for(int l = 1; l<=i; l++){
			if(dp1[l][i]){
				dp2[i] = min(dp2[i], dp2[l-1] + 1); 
			}
		}
	}
	cout << dp2[N] << "\n";
}