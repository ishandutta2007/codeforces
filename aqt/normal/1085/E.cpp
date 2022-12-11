
// Problem : E. Vasya and Templates
// Contest : Codeforces - Technocup 2019 - Elimination Round 4
// URL : https://codeforces.com/problemset/problem/1085/E
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N, K;
string s, a, b, t;
char fun[300];
bool tkn[300];

bool solve(int idx, bool bor){
	//cout << idx << " " << t << endl;
	if(idx == N){
		return 1;
	}
	if(!fun[s[idx]]){
		if(bor){
			if(!tkn[a[idx]]){
				tkn[a[idx]] = 1;
				fun[s[idx]] = a[idx];
				t.push_back(fun[s[idx]]);
				if(solve(idx+1, 1)){
					return 1;
				}
				tkn[a[idx]] = 0;
				t.pop_back();
				fun[s[idx]] = 0;
			}
			for(char c = a[idx]+1; c<K+'a'; c++){
				if(!tkn[c]){
					tkn[c] = 1;
					fun[s[idx]] = c;
					t.push_back(c);
					if(solve(idx+1, 0)){
						return 1;
					}
					tkn[c] = 0;
					t.pop_back();
					fun[s[idx]] = 0;
					break;
				}
			}
			return 0;
		}
		for(char c = 'a'; c<K+'a'; c++){
			if(!tkn[c]){
				tkn[c] = 1;
				fun[s[idx]] = c;
				t.push_back(c);
				if(solve(idx+1, 0)){
					return 1;
				}
				tkn[c] = 0;
				t.pop_back();
				fun[s[idx]] = 0;
				break;
			}
		}
		return 0;
	}
	else{
		t.push_back(fun[s[idx]]);
		if(!bor || t[idx] >= a[idx]){
			if(solve(idx+1, bor && t[idx] == a[idx])){
				return 1;
			}
		}
		t.pop_back();
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> K;
		cin >> s >> a >> b;
		t = "";
		N = s.size();
		fill(fun, fun+300, 0);
		fill(tkn, tkn+300, 0);
		//cout << "hi " << T << endl;
		if(!solve(0, 1)){
			cout << "NO\n";
			continue;
		}
		bool bor = 1;
		for(int i = 0; i<N; i++){
			if(t[i] != b[i]){
				if(t[i] > b[i]){
					bor = 0;
				}
				break;
			}
		}
		if(bor){
			cout << "YES\n";
			for(char c = 'a'; c<'a' + K; c++){
				if(!fun[c]){
					for(char d = 'a'; d<'a'+K; d++){
						if(!tkn[d]){
							tkn[d] = 1;
							fun[c] = d;
							break;
						}
					}
				}
				cout << (fun[c]);
			}
			cout << "\n";
		}
		else{
			cout << "NO\n";
		}
	}
}