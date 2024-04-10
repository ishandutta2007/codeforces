
// Problem : B. Irreducible Anagrams
// Contest : Codeforces Round #616 (Div. 1)
// URL : https://codeforces.com/contest/1290/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

string s;
int pre[26][200005];
int Q, N;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	N = s.size();
	for(int i = 1; i<=N; i++){
		pre[s[i-1]-'a'][i]++;
	}
	for(int c = 0; c<26; c++){
		for(int i = 1; i<=N; i++){
			pre[c][i] += pre[c][i-1];
		}
	}
	cin >> Q;
	while(Q--){
		int l, r;
		cin >> l >> r;
		bool yes = (l==r);
		yes |= (s[l-1] != s[r-1]);
		int cnt = 0;
		for(int c = 0; c<26; c++){
			if(pre[c][r]-pre[c][l-1] > 0){
				cnt++;
			}
		}
		yes |= (cnt >= 3);
		if(yes){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}