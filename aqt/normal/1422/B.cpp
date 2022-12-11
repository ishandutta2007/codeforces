
// Problem : B. Nice Matrix
// Contest : Codeforces - Codeforces Round #675 (Div. 2)
// URL : https://codeforces.com/contest/1422/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[105][105];
int srt[4];

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
		long long ans = 0;
		for(int i = 1; i<=(N)/2; i++){
			for(int j = 1; j<=(M)/2; j++){
				srt[0] = arr[i][j];
				srt[1] = arr[N+1-i][j];
				srt[2] = arr[i][M+1-j];
				srt[3] = arr[N+1-i][M+1-j];
				sort(srt, srt+4);
				for(int k = 0; k<4; k++){
					ans += abs(srt[k] - srt[1]);
				}
			}
		}
		if(N%2 == 1){
			for(int j = 1; j<=M/2; j++){
				ans += abs(arr[(N+1)/2][j] - arr[(N+1)/2][M+1-j]);
			}
		}
		if(M%2 == 1){
			for(int i = 1; i<=N/2; i++){
				ans += abs(arr[i][(M+1)/2] - arr[N+1-i][(M+1)/2]);
			}
		}
		cout << ans << "\n";
	}
}