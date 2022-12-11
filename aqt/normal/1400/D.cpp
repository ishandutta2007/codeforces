
// Problem : D. Zigzags
// Contest : Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1400/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[3005];
int dif[3005];
int sum[3005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		fill(sum+1, sum+1+N, 0);		
		long long ans = 0;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			fill(dif, dif+N+2, 0);
			for(int j = 1; j<i; j++){
				if(arr[j] == arr[i]){
					dif[j+1]++;
					dif[i]--;
					ans += sum[j];
				}
			}
			for(int j = 1; j<=i; j++){
				dif[j] += dif[j-1];
				sum[j] += dif[j];
			}
		}
		cout << ans << "\n";
	}
}