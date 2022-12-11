
// Problem : C. Pluses and Minuses
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1373/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int pre[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int N = s.size();
		for(int i = 1; i<=s.size(); i++){
			pre[i] = pre[i-1] + (s[i-1] == '+' ? 1 : -1);
		}
		int idx = 1;
		long long ans = 0;
		for(int t = 0; idx<=N; t++){
			while(idx<=N && pre[idx]+t >= 0){
				idx++;
			}
			ans += min(idx, N);
		}
		cout << ans << "\n";
	}
}