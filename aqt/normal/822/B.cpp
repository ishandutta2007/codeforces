
// Problem : B. Crossword solving
// Contest : Codeforces - Codeforces Round #422 (Div. 2)
// URL : https://codeforces.com/contest/822/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	string s, t;
	cin >> s >> t;
	int mn = N*N, idx = -1;
	for(int st = 0; st+N<=M; st++){
		int cnt = 0;
		for(int i = 0; i<N; i++){
			if(s[i] != t[i+st]){
				cnt++;
			}
		}
		if(cnt < mn){
			mn = cnt;
			idx = st;
		}
	}
	cout << mn << "\n";
	for(int i = 0; i<N; i++){
		if(s[i] != t[idx+i]){
			cout << i+1 << " ";
		}
	}
}