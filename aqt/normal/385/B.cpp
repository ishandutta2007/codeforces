
// Problem : B. Bear and Strings
// Contest : Codeforces - Codeforces Round #226 (Div. 2)
// URL : https://codeforces.com/contest/385/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int N;
	cin >> s;
	N = s.size();
	int ans = 0;
	for(int i = 0; i<N; i++){
		bool b = 0;
		for(int j = i+3; j<N; j++){
			b |= (s.substr(j-3, 4) == "bear");
			ans += b;
		}
	}
	cout << ans;
}