
// Problem : E. Different Subsets For All Tuples
// Contest : Codeforces - Educational Codeforces Round 11
// URL : https://codeforces.com/problemset/problem/660/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long N, M;
const long long MOD = 1e9+7;

const long long mult(long long a, long long b){
	return (a*b)%MOD;
}

const long long qikpow(long long b, long long e){
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

const long long add(long long a, long long b){
	return (a+b)%MOD;
}

const long long divd(long long a, long long b){
	return mult(a, qikpow(b, MOD-2));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	long long cur = qikpow(M, N);
	long long ans = mult(2, cur);
	const long long C = divd(M-1, M);
	for(long long l = 2; l<=N; l++){
		cur = add(cur, mult(cur, C));
		ans = add(ans, cur);
	}
	cout << ans;
}