
// Problem : C. Binary String Reconstruction
// Contest : Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1400/problem/C
// Memory Limit : 256 MB
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
		string s;
		cin >> s;
		int x;
		cin >> x;
		int N = s.size();
		vector<char> ans(N, '1');
		for(int i = 0; i<N; i++){
			if(s[i] == '0'){
				if(i+x < N){
					ans[i+x] = '0';
				}
				if(i-x >= 0){
					ans[i-x] = '0';
				}
			}
		}
		bool b = 1;
		for(int i = 0; i<N; i++){
			if(s[i] == '1'){
				bool pos = 0;
				if(i+x < N && ans[i+x] == '1'){
					pos = 1;
				}
				if(i-x >= 0 && ans[i-x] == '1'){
					pos = 1;
				}
				if(!pos){
					b = 0;
				}
			}
		}
		if(b){
			for(char n : ans){
				cout << n;
			}
		}
		else{
			cout << -1;
		}
		cout << "\n";
	}
}