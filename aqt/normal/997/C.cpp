
// Problem : C. Sky Full of Stars
// Contest : Codeforces - Codeforces Round #493 (Div. 1)
// URL : https://codeforces.com/contest/997/problem/C
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long fact[1000005];
const long long MOD = 998244353;

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e>>1);
	ret = mult(ret, ret);
	if(e&1){
		ret = mult(ret, b);
	}
	return ret;
}

long long divd(long long a, long long b){
	return mult(a, qikpow(b, MOD-2));
}

long long sub(long long a, long long b){
	a = add(a, -b);
	if(a < 0){
		a += MOD;
	}
	return a;
}

long long choose(long long n, long long r){
	return divd(fact[n], mult(fact[r], fact[n-r]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	long long ans = 0;
	fact[0] = 1;
	for(int i = 1; i<=N; i++){
		fact[i] = mult(fact[i-1], i);
	}
	for(int x = 0; x<N; x++){
		long long p = qikpow(3, x);
		long long k = sub(qikpow(sub(1, p), N), qikpow(sub(0, p), N)); 
		ans = add(ans, mult(mult(choose(N, x), ((x&1)?MOD-1 : 1)), k));
	}	
	ans = mult(ans, MOD-3);
	for(int x = 1; x<=N; x++){
		ans = add(ans, mult(mult(2, choose(N, x)), mult((x&1) ? 1 : MOD - 1, qikpow(3, 1LL*N*N-N*x+x))));
	}
	cout << ans;
}