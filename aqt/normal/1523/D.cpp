
// Problem : D. Love-Hate
// Contest : Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1523/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
long long msk[200005];
int dp[1 << 15];
mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i =1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			msk[i] *= 2;
			char c;
			cin >> c;
			msk[i] |= (c == '1');
		}
	}
	shuffle(msk + 1, msk + 1 + N, rando);
	long long ans = 0;
	for(int i = 1; i <= min(15, N); i++){
		memset(dp, 0, sizeof dp);
		vector<long long> v;
		for(long long b = M - 1; b >= 0; b--){
			if(msk[i] >> b & 1){
				v.emplace_back((1LL << b));
			}
		}
		for(int j = 1; j <= N; j++){
			int tot = 0;
			for(int i = 0; i < v.size(); i++){
				if(msk[j] & v[i]){
					tot += (1 << i);
				}
			}
			dp[tot]++;
		}
		for(int b = 0; b < v.size(); b++){
			for(int m = (1 << v.size()) - 1; m >= 0; m--){
				if(!(m >> b & 1)){
					dp[m] += dp[m | (1 << b)];
				}
			}
		}
		for(int m = 0; m < 1 << v.size(); m++){
			if(dp[m] >= (N + 1) / 2 && __builtin_popcount(m) > __builtin_popcountll(ans)){
				long long tmp = 0;
				for(int k = 0; k < v.size(); k++){
					if(m >> k & 1){
						tmp += v[k];
					}
				}
				ans = tmp;
			}
		}		
	}
	for(long long b = M - 1; b >= 0; b--){
		cout << (ans >> b & 1);
	}
}