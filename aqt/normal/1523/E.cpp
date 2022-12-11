
// Problem : E. Crypto Lights
// Contest : Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1523/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N, K;
long long fact[200005];
long long invf[200005];
const long long MOD = 1e9 + 7;

long long mult(long long a, long long b){
	return a * b % MOD;
}

long long add(long long a, long long b){
	return (a + b) % MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e / 2);
	ret = mult(ret, ret);
	if(e & 1){
		ret = mult(ret, b);
	}
	return ret;
}

long long choose(long long n, long long r){
	if(n < 0 || n < r){
		return 0;
	}
	return mult(fact[n], mult(invf[r], invf[n - r]));
}

long long pick(long long n, long long r){
	return mult(choose(n, r), fact[r]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	fact[0] = invf[0] = 1;
	for(int i = 1; i <= 200000; i++){
		fact[i] = mult(fact[i - 1], i);
		invf[i] = qikpow(fact[i], MOD - 2);
	}
	while(T--){
		cin >> N >> K;
		long long out = 1;
		for(int i = 1; N - (i - 1) * (K - 1) >= 0; i++){
			out = add(out, mult(pick(N - (i - 1) * (K - 1), i), qikpow(pick(N, i), MOD - 2)));
		}
		cout << out << "\n";
	}
}