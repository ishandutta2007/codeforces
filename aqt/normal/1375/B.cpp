
// Problem : B. Neighbor Grid
// Contest : Codeforces - Codeforces Global Round 9
// URL : https://codeforces.com/contest/1375/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[305][305];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		bool can = 1;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				cin >> arr[i][j];
				int cnt = 4;
				if(i == 1){
					cnt--;
				}
				if(i == N){
					cnt--;
				}
				if(j == 1){
					cnt--;
				}
				if(j == M){
					cnt--;
				}
				if(arr[i][j] > cnt){
					can = 0;
				}
				arr[i][j] = cnt;
			}
		}
		if(can){
			cout << "YES\n";
			for(int i = 1; i<=N; i++){
				for(int j = 1; j<=M; j++){
					cout << arr[i][j] << " ";
				}
				cout << "\n";
			}
		}
		else{
			cout << "NO\n";
		}
	}
}