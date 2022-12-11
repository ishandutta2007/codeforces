
// Problem : B. New Year and North Pole
// Contest : Codeforces - Good Bye 2016
// URL : https://codeforces.com/contest/750/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int v = 0;
	while(N--){
		int k;
		string s;
		cin >> k >> s;
		if(s == "South"){
			if(k+v > 20000){
				cout << "NO\n";
				return 0;
			}
			v += k;
		}
		else if(s == "North"){
			if(v-k < 0){
				cout << "NO\n";
				return 0;
			}
			v -= k;
		}
		else {
			if(v == 0 || v == 20000){
				cout << "NO\n";
				return 0;
			}
		}
	}
	if(v){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}