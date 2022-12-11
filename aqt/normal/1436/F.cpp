
// Problem : F. Sum Over Subsets
// Contest : Codeforces - Codeforces Round #678 (Div. 2)
// URL : https://codeforces.com/contest/1436/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
const int M = 100000;
const long long MOD = 998244353;
long long fre[100005];
int mob[100005];
bool sieve[100005];

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

long long mult(long long a, long long b){
	return (a%MOD*b%MOD)%MOD;
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		cin >> fre[n];
	}
	fill(mob, mob+1+M, 1);
	for(int n = 2; n<=M; n++){
		if(!sieve[n]){
			for(int k = n; k<=M; k+=n){
				mob[k] *= -1;
				sieve[k] = 1;
			}
			for(long long k = 1LL * n * n; k<=M; k+=n*n){
				mob[k] = 0;
			}
		}
		if(mob[n] == -1){
			mob[n] = MOD - 1;
		}
	}
	long long ans = 0;
	for(int g = 1; g<=M; g++){
		long long tot = 0;
		long long sz = 0;
		long long sum = 0;
		for(int k = g; k<=M; k+=g){
			tot = add(tot, mult(fre[k], k));
			sz += fre[k];
		}
		const long long v = qikpow(2, sz-2);
		const long long u = qikpow(2, sz-3);
		for(int k = g; k<=M; k+=g){
			/*
			sum = add(sum, mult(mult(fre[k], k), qikpow(2, sz-1)));
			cout << sum-MOD << endl;
			sum = sub(sum, mult(add(qikpow(3, sz-1), qikpow(2, sz-1)), mult(fre[k], k)));
			cout << sum-MOD << endl;
			*/
			
			sum = add(sum, mult(mult(sz-1, v), mult(fre[k], mult(k, k))));
			//cout << sum-MOD << endl;
			sum = add(sum, mult(add(mult(sz-2, u), v), mult(fre[k], mult(k, sub(tot, k)))));
		}
		ans = add(ans, mult(mob[g], sum));
	}
	cout << ans;
}