
// Problem : B. 01 Game
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1373/problem/B
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
		string s;
		cin >> s;
		int cnt0 = 0, cnt1 = 0;
		for(char c : s){
			if(c == '0'){
				cnt0++;
			}
			else{
				cnt1++;
			}
		}
		if(min(cnt0, cnt1)%2 == 0){
			cout << "net\n";
		}
		else{
			cout << "da\n";
		}
	}
}