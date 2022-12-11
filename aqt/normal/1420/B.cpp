
// Problem : B. Rock and Lever
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int cnt[50];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		fill(cnt, cnt+50, 0);
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			cnt[31-__builtin_clz(n)]++;
		}
		long long ans = 0;
		for(int i = 0; i<50; i++){
			ans += 1LL*cnt[i]*(cnt[i]-1)/2;
		}
		cout << ans << "\n";
	}
}