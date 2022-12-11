
// Problem : B. Johnny and Grandmaster
// Contest : Codeforces - Codeforces Round #647 (Div. 1) - Thanks, Algo Muse!
// URL : https://codeforces.com/contest/1361/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret= qikpow(b, e/2);
	ret *= ret;
	ret %= MOD;
	if(e&1){
		return ret * b %MOD;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, P;
		cin >> N >> P;
		vector<int> v;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			v.push_back(n);
		}
		if(P == 1){
			cout << N%2 << "\n";
			continue;
		}
		sort(v.begin(), v.end(), greater<int>());
		long long ans = 0;
		for(int i = 0; i<N; ){
			ans += qikpow(P, v[i]);
			ans %= MOD;
			long long lft = 1, cur = v[i];
			i++;
			while(i < N && lft){
				while(cur != v[i] && lft < N){
					cur--;
					lft *= P;
				}
				lft--;
				ans -= qikpow(P, v[i]);
				ans %= MOD;
				if(ans < 0){
					ans += MOD;
				}
				i++;
			}
		}
		cout << ans << "\n";
	}
}