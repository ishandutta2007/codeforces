
// Problem : A. Level Statistics
// Contest : Educational Codeforces Round 85 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1334/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		int p, c;
		int lstp = 0, lstc = 0;
		bool b = 1;
		while(N--){
			cin >> p >> c;
			if(p-lstp < c-lstc){
				b = 0;
			}
			if(p < lstp){
				b = 0;
			}
			if(c < lstc){
				b = 0;
			}
			lstp = p;
			lstc = c;
		}
		if(b){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}