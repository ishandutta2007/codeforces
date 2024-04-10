
// Problem : C. ABBB
// Contest : Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1428/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int cnt = 0;
		string s;
		cin >> s;
		for(char c : s){
			if(c == 'B'){
				if(cnt){
					cnt--;
				}
				else{
					cnt++;
				}
			}
			else{
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}