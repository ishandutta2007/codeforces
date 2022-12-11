
// Problem : E. Devu and Flowers
// Contest : Codeforces - Codeforces Round #258 (Div. 2)
// URL : https://codeforces.com/contest/451/problem/E
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long arr[25], inv[25];
const long long MOD = 1e9+7;

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = mult(ret, ret);
	if(e&1){
		ret = mult(ret, b);
	}
	return ret;
}

long long choose(long long n, long long r){
	if(n < 0 || r > n){
		return 0;
	}
	r = max(r, n-r);
	long long ret = 1;
	for(long long k = n; k>r; k--){
		ret = mult(ret, k%MOD);
	}
	for(long long i = 1; i<=n-r; i++){
		ret = mult(ret, inv[i]);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	long long S;
	cin >> N >> S;
	for(int i = 0; i<N; i++){
		cin >> arr[i];
	}
	for(int i = 0; i<=N; i++){
		inv[i] = qikpow(i, MOD-2);
	}
	long long ans = 0;
	for(int m = 0; m<1<<N; m++){
		long long tot = S;
		for(int n = 0; n<N; n++){
			if(m>>n&1){
				tot -= arr[n]+1;
			}
		}
		tot = choose(tot+N-1, N-1);
		//cout << tot << "\n";
		if((__builtin_popcount(m))%2 == 1){
			ans -= tot;
			ans += MOD;
			ans %= MOD;
		}
		else{
			ans += tot;
			ans %= MOD;
		}
	}
	cout << ans;
}