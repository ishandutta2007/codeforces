
// Problem : E. Necklace Assembly
// Contest : Codeforces - Codeforces Round #650 (Div. 3)
// URL : https://codeforces.com/contest/1367/problem/E
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
		int N, K;
		cin >> N >> K;
		string s;
		cin >> s;
		vector<int> cnt(30);
		for(char c : s){
			cnt[c-'a']++;
		}
		vector<int> fact;
		for(int i = 1; i<=(K); i++){
			if(K%i == 0){
				fact.push_back(i);
			}
		}
		sort(fact.begin(), fact.end());
		int ans = 0;
		for(int i = 1; i<=N; i++){
			int c = 0;
			for(int a = 0; a<26; a++){
				c += cnt[a]/i;
			}
			if(!c){
				break;
			}
			ans = max(ans, *(--upper_bound(fact.begin(), fact.end(), c))*i);
		}
		cout << ans << "\n";
	}
}