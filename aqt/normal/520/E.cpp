
// Problem : E. Pluses everywhere
// Contest : Codeforces - Codeforces Round #295 (Div. 2)
// URL : https://codeforces.com/contest/520/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, M = 1000000;
const long long MOD = 1e9+7;
long long fact[1000005];
long long sum[10];

long long mult(long long a, long long b){
	return (a*b)%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
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

long long divd(long long a, long long b){
	return mult(a, qikpow(b, MOD-2));
}

long long choose(long long n, long long r){
	if(r > n){
		return 0;
	}
	return divd(fact[n], mult(fact[r], fact[n-r]));
}

long long sub(long long a, long long b){
	return add(MOD, add(a, -b));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	if(K == 0){
		long long ans = 0;
		for(int i = 0; i<N; i++){
			ans = mult(ans, 10);
			char c;
			cin >> c;
			ans = add(ans, c-'0');
		}
		cout << ans << "\n";
		return 0;
	}
	fact[0] = 1;
	for(int i=1 ; i<=M; i++){
		fact[i] = mult(fact[i-1], i);
	}
	for(int d = 0; d<10; d++){
		for(int i = 0; i<N-1; i++){
			sum[d] = add(sum[d], mult(mult(d, qikpow(10, i)), choose(N-1-i-1, K-1)));
		}
	}
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		char c;
		cin >> c;
		int n = c-'0';
		ans = add(ans, sum[n]);
		ans = add(ans, mult(mult(n, qikpow(10, N-i)), choose(i-1, K)));
		//cout << ans << "\n";
		for(int d = 0; d<10; d++){
			sum[d] = sub(sum[d], mult(mult(d, qikpow(10, N-i-1)), choose(i-1, K-1)));
		}
	}
	cout << ans;
}