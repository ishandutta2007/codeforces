
// Problem : D. Fuzzy Search
// Contest : Codeforces - Codeforces Round #296 (Div. 1)
// URL : https://codeforces.com/contest/528/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
string s, t;
bitset<200005> bs[30];
int dif[30][200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	cin >> s >> t;
	for(int i = 0; i<N; i++){
		dif[s[i]-'A'][max(0, i-K)]++;
		dif[s[i]-'A'][min(N, i+K+1)]--;
	}
	for(int c = 0; c<26; c++){
		for(int i = 0; i<N; i++){
			bs[c][i] = !!dif[c][i];
			dif[c][i+1] += dif[c][i];
		}
	}
	bitset<200005> init;
	for(int i = 0; i<N; i++){
		init[i] = 1;
	}
	for(int i = 0; i<M; i++){
		init &= (bs[t[i]-'A']>>i);
	}
	cout << init.count() << "\n";
}