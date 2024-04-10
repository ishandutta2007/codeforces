
// Problem : C. Nastya and a Wardrobe
// Contest : Codeforces - Codeforces Round #489 (Div. 2)
// URL : https://codeforces.com/contest/992/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long x, k;
const long long MOD = 1e9+7;

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = ret * ret % MOD;
	if(e&1){
		ret = ret * b;
		ret %= MOD;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> x >> k;
	if(!x){
		cout << 0 << "\n";
		return 0;
	}
	x %= MOD;
	x = (x * qikpow(2, k+1))%MOD;
	x -= qikpow(2, k);
	x %= MOD;
	x += MOD;
	x++;
	x%=MOD;
	cout << x;
}