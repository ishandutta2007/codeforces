
// Problem : F. Substrings in a String
// Contest : Codeforces - Codecraft-18 and Codeforces Round #458 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/914/problem/F
// Memory Limit : 256 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int Q;
bitset<100005> st[30];
bitset<100005> init;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> Q;
	N = s.size();
	for(int i = 0; i<N; i++){
		st[s[i]-'a'][i+1] = 1;
		init[i+1] = 1;
	}
	while(Q--){
		int c;
		cin >> c;
		if(c == 1){
			int p;
			char k;
			cin >> p >> k;
			st[s[p-1]-'a'][p]= 0;
			s[p-1] = k;
			st[s[p-1]-'a'][p] = 1;
		}
		else{
			int l, r;
			string t;
			cin >> l >> r >> t;
			int M = t.size();
			if(r - l + 1 < M){
				cout << 0 << "\n";
				continue;
			}
			auto ans = init;
			for(int i = 0; i<M; i++){
				ans &= (st[t[i]-'a']>>i);
				//cout << ans.to_string() << "\n";
			}
			//cout << (ans>>(l-1)).to_string() << " " << (ans>>(r-M+1)).to_string() << "\n";
			cout << (ans>>(l)).count() - (ans>>(r-M+2)).count() << "\n";
		}
	}
}