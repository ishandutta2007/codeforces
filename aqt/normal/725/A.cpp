
// Problem : A. Jumping Ball
// Contest : Codeforces - Canada Cup 2016
// URL : https://codeforces.com/contest/725/problem/A
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
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i<N; i++){
		if(s[i] == '>'){
			break;
		}
		ans++;
	}
	for(int i = N-1; i>=0; i--){
		if(s[i] == '<'){
			break;
		}
		ans++;
	}
	cout << ans;
}