
// Problem : B. Blown Garland
// Contest : Codeforces - Codeforces Round #392 (Div. 2)
// URL : https://codeforces.com/contest/758/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int pos[30];
int cnt[30];
char c[30];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for(int i = 0; i<s.size(); i++){
		if(s[i] >= 'A' && s[i] <='Z'){
			pos[s[i]-'A'] = i%4;
			c[i%4] = s[i];
		}
	}
	for(int i = 0; i<s.size(); i++){
		if(s[i] == '!'){
			cnt[c[i%4]-'A']++;
		}
	}
	cout << cnt['R'-'A'] << " " << cnt[1] << " " << cnt['Y'-'A'] << " " << cnt['G' - 'A'];
}