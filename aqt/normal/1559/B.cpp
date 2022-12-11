
// Problem : B. Mocha and Red and Blue
// Contest : Codeforces - Codeforces Round #738 (Div. 2)
// URL : https://codeforces.com/contest/1559/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

char f(char c){
	return (c == 'R' ? 'B' : 'R');
}

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
		bool foundone = 0;
		for(int i = 0; i < N; i++){
			if(s[i] != '?'){
				foundone = 1;
				for(int j = i-1; j >= 0; j--){
					s[j] = f(s[j+1]);
				}
				break;
			}
		}
		if(!foundone){
			s[0] = 'R';
			for(int i = 1; i < N; i++){
				s[i] = f(s[i-1]);
			}
		}
		else{
			for(int i = 1; i < N; i++){
				if(s[i] == '?'){
					s[i] = f(s[i-1]);
				}
			}
		}
		cout << s << "\n";
	}
}