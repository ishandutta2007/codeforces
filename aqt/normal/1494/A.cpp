
// Problem : A. ABC String
// Contest : Codeforces - Educational Codeforces Round 105 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1494/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> s;
		bool exist = 0;
		for(int msk = 0; msk < 8; msk++){
			bool good = 1;
			int pre = 0;
			for(char c : s){
				pre += (msk>>(c - 'A')&1)*2-1;
				if(pre < 0){
					good = 0;
				}
			}
			if(pre){
				good = 0;
			}
			if(good){
				exist = 1;
				break;
			}
		}
		cout << (exist ? "YES\n" : "NO\n");
	}
}