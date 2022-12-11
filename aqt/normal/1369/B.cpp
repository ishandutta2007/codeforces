
// Problem : B. AccurateLee
// Contest : Codeforces - Codeforces Round #652 (Div. 2)
// URL : https://codeforces.com/contest/1369/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
		//string t = "";
		stack<int> stk;
		bool seen1 = 0;
		int lst0 = -1;
		for(int i = 0; i<N; i++){
			if(s[i] == '1'){
				stk.push(i);
				seen1 = 1;
			}
			else{
				while(stk.size()){
					s[stk.top()] = '2';
					stk.pop();
				}
				if(seen1){
					s[i] = '2';
					lst0 = i;
				}
			}
		}
		if(lst0+1){
			s[lst0] = '0';
		}
		for(char c : s){
			if(c != '2'){
				cout << c;
			}
		}
		cout << "\n";
	}
}