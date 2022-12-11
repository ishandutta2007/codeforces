
// Problem : E. Modular Stability
// Contest : Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1359/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long long MOD = 998244353;
long long fact[500005];

long long mult(long long a, long long b){
	return (a*b)%MOD;
}

long long qikpow(long long a, long long b){
	if(!b){
		return 1;
	}
	long long ret= qikpow(a, b/2);
	ret = mult(ret, ret);
	if(b&1){
		ret = mult(ret, a);
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	swap(N, K);
	long long ans = 0;
	fact[0] = 1;
	for(int i = 1; i<=K; i++){
		fact[i] = mult(fact[i-1], i);
	}
	for(int i = 1; i<=K; i++){
		long long amt = K/i;
		if(amt < N){
			break;
		}
		//cout << amt << " " << fact[amt] << "\n";
		long long tot = 1;
		tot = mult(tot, fact[amt-1]);
		tot= mult(tot, qikpow(fact[N-1], MOD-2));
		tot= mult(tot, qikpow(fact[amt-N], MOD-2));
		ans += tot;
		ans %= MOD;
	}
	cout << ans;
}