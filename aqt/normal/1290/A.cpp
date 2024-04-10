
// Problem : A. Mind Control
// Contest : Codeforces Round #616 (Div. 1)
// URL : https://codeforces.com/contest/1290/problem/A
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int T;
int arr[3505];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N , M , K;
		cin >> N >> M >> K;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		K = min(K, M-1);
		int X = M - K - 1;
		int ans = 0;
		for(int k = 0; k<=K; k++){
			int mn = INT_MAX;
			for(int l = 0; l<=X; l++){
				mn = min(mn, max(arr[l+1+k], arr[N-(X-l)-(K-k)]));
			}
			ans = max(mn, ans);
		}
		cout << ans << "\n";
	}
}