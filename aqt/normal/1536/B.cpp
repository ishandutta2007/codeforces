
// Problem : B. Prinzessin der Verurteilung
// Contest : Codeforces - Codeforces Round #724 (Div. 2)
// URL : https://codeforces.com/contest/1536/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		cin >> s;
		set<string> st;
		for(int i = 0; i < N; i++){
			for(int j = 1; i + j <= N && j <= 3; j++){
				st.insert(s.substr(i, j));
			}
		}
		string tst = "";
		string ans = "";
		for(char a = 'a'; a <= 'z' && !ans.size(); a++){
			tst.push_back(a);
			if(!st.count(tst)){
				ans = tst;
			}
			tst.pop_back();
		}
		for(char a = 'a'; a <= 'z' && !ans.size(); a++){
			tst.push_back(a);
			for(char b = 'a'; b <= 'z' && !ans.size(); b++){
				tst.push_back(b);
				if(!st.count(tst)){
					ans = tst;
				}
				tst.pop_back();
			}
			tst.pop_back();
		}
		for(char a = 'a'; a <= 'z' && !ans.size(); a++){
			tst.push_back(a);
			for(char b = 'a'; b <= 'z' && !ans.size(); b++){
				tst.push_back(b);
				for(char c = 'a'; c <= 'z' && !ans.size(); c++){
					tst.push_back(c);
					if(!st.count(tst)){
						ans = tst;
					}
					tst.pop_back();
				}
				tst.pop_back();
			}
			tst.pop_back();
		}
		cout << ans << "\n";
	}
}