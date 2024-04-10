
// Problem : E. K-periodic Garland
// Contest : Codeforces - Codeforces Round #642 (Div. 3)
// URL : https://codeforces.com/contest/1353/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int pre[1000005], suf[1000005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		string s;
		cin >> s;
		vector<int> cnt(K);
		int tot = 0;
		for(int i = 0; i<s.size(); i++){
			if(s[i] == '1'){
				cnt[i%K]++;
				tot++;
			}
		}
		int ans = tot;
		for(int r = 0; r<K; r++){
			int cum = 0, mx = 0;
			int c = 1;
			for(int i = r; i<N; i+=K, c++){
				pre[c] = pre[c-1] + (s[i] == '1');
			}
			suf[c] = 0;
			for(int i = (N/K*K+r >= N ? N/K*K+r-K : N/K*K+r); i >= 0; i -= K){
				c--;
				suf[c] = suf[c+1] + (s[i] == '1');
			}
			c = 1;
			for(int i = r; i<N; i+=K, c++){
				cum += (s[i] == '0');
				ans = min(cum - mx + suf[c+1] + tot - cnt[r], ans);
				mx = max(mx, cum - pre[c-1]);
			}
		}
		cout << ans << "\n";
	}
}