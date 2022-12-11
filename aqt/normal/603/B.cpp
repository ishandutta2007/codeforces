
// Problem : B. Moodular Arithmetic
// Contest : Codeforces - Codeforces Round #334 (Div. 1)
// URL : https://codeforces.com/contest/603/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long P, K;
bool vis[1000005];
int cnt[1000005];
long long MOD = 1e9+7;

int dfs(int n){
	if(vis[n]){
		return 0;
	}
	vis[n] = 1;
	return dfs((n*K)%P)+1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> P >> K;
	for(int i = 0; i<P; i++){
		int C = dfs(i);
		cnt[C]++;
	}
	if(K == 0){
		long long ans = 1;
		for(int i = 1; i<P; i++){
			ans *= P;
			ans %= MOD;
		}
		cout << ans << "\n";
		return 0;
	}
	long long ans = 1;
	for(int i = 1; i<=P; i++){
		if(cnt[i]){
			//cout << i << " " << cnt[i] << "\n";
			long long tot = 0;
			for(int j =1 ; j<=i; j++){
				if(i%j == 0){
					tot += cnt[j] * j;
					tot %= MOD;
				}
			}
			for(int k = 0; k<cnt[i]; k++){
				ans *= tot;
				ans %= MOD;
			}
			ans %= MOD;
		}
	}
	cout << ans;
}