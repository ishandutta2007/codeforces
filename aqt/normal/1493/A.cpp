
// Problem : A. Anti-knapsack
// Contest : Codeforces - Codeforces Round #705 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1493/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		cout << K - (K+1)/2 + N - K << "\n";
		for(int i = (K+1)/2; i<K; i++){
			cout << i << " ";
		}
		for(int i = K+1; i<=N; i++){
			cout << i << " ";
		}
		cout << "\n";
	}
}