
// Problem : C. Palindromic Paths
// Contest : Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1366/problem/C
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[35][35];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				cin >> arr[i][j];
			}
		}
		int ans = 0;
		for(int k = 2; k<=(N+M+1)/2; k++){
			int cnt0 = 0, cnt1 = 0;
			for(int r = 1; r<=N; r++){
				int c = k-r;
				if(c <= M && c > 0){
					//cnt += 2*arr[r][c]-1;
					if(arr[r][c] == 0){
						cnt0++;
					}
					else{
						cnt1++;
					}
				}
				c = N+M-k+2-r;
				if(c <= M && c > 0){
					//cnt += 2*arr[r][c]-1;
					if(arr[r][c] == 0){
						cnt0++;
					}
					else{
						cnt1++;
					}
				}
			}
			ans += min(cnt0, cnt1);
		}
		cout << ans << "\n";
	}
}