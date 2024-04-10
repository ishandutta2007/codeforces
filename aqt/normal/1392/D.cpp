
// Problem : D. Omkar and Bed Wars
// Contest : Codeforces - Codeforces Global Round 10
// URL : https://codeforces.com/contest/1392/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		bool allR = 1, allL = 1;
		cin >> N;
		string s;
		cin >> s;
		for(char c : s){
			if(c == 'L'){
				allR = 0;
			}
			else{
				allL = 0;
			}
		}
		if(allL || allR){
			cout << (N+2)/3 << "\n";
			continue;
		}
		int pre = 0;
		while(s[pre] == s[0]){
			pre++;
		}
		s = s.substr(pre) + s.substr(0, pre);
		int cnt = 1;
		long long ans = 0;
		for(int i = 1; i<N; i++){
			if(s[i] == s[i-1]){
				cnt++;
			}
			else{
				ans += (cnt)/3;
				cnt = 1;
			}
		}
		ans += (cnt)/3;
		cout << ans << "\n";
	}
}