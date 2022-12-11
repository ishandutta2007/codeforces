
// Problem : E. Side Transmutations
// Contest : Codeforces - Educational Codeforces Round 52 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1065/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, A;
const long long MOD = 998244353;

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long qikpow(long long a, long long b){
	if(!b){
		return 1;
	}
	long long ret = qikpow(a, b/2);
	ret = mult(ret,ret);
	if(b&1){
		ret = mult(ret, a);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> A;
	int lst = 0;
	long long ans = 1;
	for(int i = 1; i<=M; i++){
		int n;
		cin >> n;
		long long p = qikpow(A, n-lst);
		//cout << p << "\n";
		//cout << mult(mult(p, 1+p), qikpow(2, MOD-2)) << "\n";
		ans = mult(ans, mult(mult(p, 1+p), qikpow(2, MOD-2)));
		lst = n;
	}
	ans = mult(ans, qikpow(A, N-lst-lst));
	cout << ans << "\n";
}