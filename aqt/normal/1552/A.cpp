
// Problem : A. Subsequence Permutation
// Contest : Codeforces - Codeforces Global Round 15
// URL : https://codeforces.com/contest/1552/problem/A
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
		int N;
		cin >> N;
		string s;
		cin >> s;
		string t = s;
		sort(t.begin(), t.end());
		int cnt = 0;
		for(int i = 0; i < s.size(); i++){
			cnt += t[i] != s[i];
		}
		cout << cnt << "\n";
	}
		
}