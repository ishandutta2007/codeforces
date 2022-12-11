// Problem : E. A Bit Similar
// Contest : Codeforces - Educational Codeforces Round 101 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1469/problem/E
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, D;
int arr[1000005];
int pre[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> N >> K;
		D = min(20, K);
		for(int i = 1; i <= N; i++){
			char c;
			cin >> c;
			arr[i] = c - '0';
			pre[i] = arr[i] + pre[i-1];	
		}
		set<int> suf;
		for(int i = K; i <= N; i++){
			if(pre[i - D] - pre[i - K] == K - D){
				int tot = 0;
				for(int t = D - 1; t >= 0; t--){
					tot *= 2;
					tot += 1 - arr[i - t];
				}				
				suf.insert(tot);
			}
		}
		bool good = 0;
		for(int v = 0; v < (1<<D); v++){
			if(!good && !suf.count(v)){
				good = 1;
				cout << "YES\n";
				for(int k = 0; k < K - D; k++){
					cout << 0;
				}
				for(int k = D - 1; k >= 0; k--){
					cout << (v >> k & 1);
				}
				cout << "\n";
				break;
			}
		}
		if(!good){
			cout << "NO\n";
		}
	}
	
}