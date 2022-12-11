
// Problem : E. Height All the Same
// Contest : Codeforces - Codeforces Round #630 (Div. 2)
// URL : https://codeforces.com/contest/1332/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret *= ret;
	ret %= MOD;
	if(e&1){
		ret *= b;
		ret %= MOD;
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long L, R, N, M;
	cin >> N >> M >> L >> R;
	if(N*M%2 == 1){
		cout << qikpow(R - L + 1, N*M) << "\n";
	}
	else{
		long long e = R/2 - (L-1)/2;
		long long o = R - L + 1 - e;
		cout << (qikpow(R - L + 1, N*M) + qikpow(e - o, N*M)) * (MOD + 1)/2 % MOD << "\n";
	}
}