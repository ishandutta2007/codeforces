
// Problem : C. Cow and Message
// Contest : Codeforces Round #621 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1307/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

string s;
long long cnt[30];
long long tbl[30][30];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int N;	
	N = s.size();	
	long long ans = 0;
	for(char c : s){
		for(int k = 0; k<26; k++){
			tbl[k][c-'a'] += cnt[k];
			ans = max(tbl[k][c-'a'], ans);
		}
		cnt[c-'a']++;
		ans = max(cnt[c-'a'] ,ans);
	}
	cout << ans << "\n";
}