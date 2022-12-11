
// Problem : C. Obtain The String
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int T;
int nxt[26][100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;	
	while(T--){
		string s, t;
		cin >> s >> t;
		for(int k = 0; k<26; k++){
			for(int i = 0; i<s.size(); i++){
				nxt[k][i] = -1;
			}
		}
		for(int t = 0; t<3; t++){
			for(int i = s.size()-1; i>=0; i--){
				for(int k = 0; k<26; k++){
					nxt[k][i] = nxt[k][(i+1)%s.size()];
				}
				nxt[s[(i+1)%s.size()]-'a'][i] = (i+1)%s.size();
			}
		}
		int idx = s.size()-1;
		int ans = 0;
		for(char c : t){
			if(nxt[c-'a'][idx] == -1){
				ans = -1;
				break;
			}
			else {
				if(nxt[c-'a'][idx] <= idx){
					ans++;
				}
				idx = nxt[c-'a'][idx];
			}
		}
		cout << ans << "\n";
	}
}