
// Problem : C. Travelling Salesman and Special Numbers
// Contest : Codecraft-18 and Codeforces Round #458 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/914/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

string s;
int N, K;
long long tri[1005][1005];
const long long MOD = 1e9+7;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> K;
	N = s.size();
	for(int i = 0; i<=N; i++){
		tri[i][0] = 1;
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=i; j++){
			tri[i][j] = (tri[i-1][j-1] + tri[i-1][j])%MOD;
		}
	}
	if(K == 0){
		cout << 1 << "\n";
		return 0;
	}
	long long ans = (K==1) ? -1 : 0;
	//cout << ans << endl;
	for(int i = 1; i<=N; i++){
		int cnt = 1;
		int temp = i;
		while(temp != 1){
			cnt++;
			temp = __builtin_popcount(temp);
		}
		if(cnt == K){
			int totb = i;
			for(int j = 1; j<=N && totb >= 0; j++){
				if(s[j-1] == '1'){
					//cout << i << " " << N-j << " " << totb << "\n";
					ans += tri[N-j][totb];
					ans %= MOD;
					totb--;
				}
			}
			if(totb == 0){
				ans++;
			}
		}
	}
	cout << ans << endl;
}