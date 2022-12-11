
// Problem : A. Domino Disaster
// Contest : Codeforces - Codeforces Round #742 (Div. 2)
// URL : https://codeforces.com/contest/1567/problem/A
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
		int N;
		cin >> N;
		string s;
		cin >> s;
		for(char c : s){
			if(c == 'U'){
				cout << 'D';
			}
			else if(c == 'D'){
				cout << 'U';
			}
			else{
				cout << c;
			}
		}
		cout << "\n";
	}
}