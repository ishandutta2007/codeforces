
// Problem : E. Placing Rooks
// Contest : Codeforces - Educational Codeforces Round 86 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1342/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
long long fact[200005];
long long MOD = 998244353;

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long sub(long long a, long long b){
	a = add(a, -b);
	if(a < 0){
		a += MOD;
	}
	return a;
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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	if(K > N-1){
		cout << 0 << "\n";
		return 0;
	}
	long long ans = 0;
	fact[0] = 1;
	for(int i = 1; i<=N; i++){
		fact[i] = mult(fact[i-1], i);
	}
	int M = N-K;
	for(int i = 0; i<=M; i++){
		long long tot = qikpow(M-i, N);
		tot = mult(tot, fact[N]);
		tot = mult(tot, qikpow(fact[M], MOD-2));
		tot = mult(tot, qikpow(fact[N-M], MOD-2));
		tot = mult(tot, fact[M]);
		tot = mult(tot, qikpow(fact[i], MOD-2));
		tot = mult(tot, qikpow(fact[M-i], MOD-2));
		//tot = mult(tot, M-i+1);
		if(i&1){
			ans = sub(ans, tot);
		}
		else{
			ans = add(ans, tot);
		}
		// cout << ans << " " << tot << "\n";
	}
	if(K){
		ans = mult(ans, 2);
	}
	cout << ans << "\n";
}