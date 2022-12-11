
// Problem : E. Omkar and Forest
// Contest : Codeforces - Codeforces Round #724 (Div. 2)
// URL : https://codeforces.com/contest/1536/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
const long long MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		int cnt = 0;
		long long ans = 1;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <=M; j++){
				char c;
				cin >> c;
				if(c == '#'){
					cnt++;
					ans *= 2;
					ans %= MOD;
				}
			}
		}
		if(cnt == N * M){
			ans += MOD - 1;
			ans %= MOD;	
		}
		cout << ans << "\n";
	}
}