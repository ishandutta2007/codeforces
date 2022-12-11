
// Problem : A. Charmed by the Game
// Contest : Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL : https://codeforces.com/contest/1558/problem/A
// Memory Limit : 512 MB
// Time Limit : 2000 ms
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
		int a, b;
		cin >> a >> b;
		vector<bool> vec(a + b + 5);
		int n = a + b;
		if((a+b)%2 == 0){
			for(int k = 0; k <= a; k++){
				if((k + b) >= n / 2 && k <= n / 2){
					vec[k + b - n / 2 + k] = 1;
				}
			}
		}
		else{
			for(int k = 0; k <= a; k++){
				if((k + b) >= n / 2 + 1 && k <= n / 2 + 1){
					vec[k + b - n / 2 - 1 + k] = 1;
					//cout << k + b - n / 2 - 1 + k << "\n";
				}
			}
			for(int k = 0; k <= a; k++){
				if((k + b) >= n / 2 && k <= n / 2){
					vec[k + b - n / 2 + k] = 1;
					//cout << k + b - n / 2 + k << "\n";
				}
			}
		}
		int cnt = 0;
		for(auto b : vec){
			cnt += b;
		}
		cout << cnt << "\n";
		for(int i = 0; i <= n; i++){
			if(vec[i]){
				cout << i << " ";
			}
		}
		cout << "\n";
	}
}