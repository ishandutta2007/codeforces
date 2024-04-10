
// Problem : D. Sasha and Interesting Fact from Graph Theory
// Contest : Codeforces - Codeforces Round #539 (Div. 1)
// URL : https://codeforces.com/contest/1109/problem/D
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
long long fact[1000005];
const long long MOD = 1e9+7;

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

long long choose(long long n, long long r){
	return mult(fact[n], qikpow(mult(fact[r], fact[n-r]), MOD-2));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	fact[0] = 1;
	for(int i = 1; i<=max(M, N); i++){
		fact[i] = mult(fact[i-1], i);
	}
	long long ans = 0;
	for(int i = 1; i<N; i++){
		if(i > M){
			break;
		}
		long long w = mult(qikpow(M, N-1-i), choose(M-1, i-1));
		long long s = mult(i+1, qikpow(N, N-i-2));
		if(N-i-2 < 0){
			s = 1;
		}
		long long p = mult(choose(N-2, i-1), fact[i-1]);
		//cout << i << " " << w << " " << s << " " << p << "\n";
		ans = add(ans, mult(w, mult(p, s)));
	}
	cout << ans;
}