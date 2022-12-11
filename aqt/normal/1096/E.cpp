
// Problem : E. The Top Scorer
// Contest : Codeforces - Educational Codeforces Round 57 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1096/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int P, R, S;
const long long MOD = 998244353;
long long fact[10005];

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long qikpow(long long a, long long b){
	if(!b){
		return 1;
	}
	long long ret = qikpow(a, b/2);
	ret = mult(ret, ret);
	if(b&1){
		ret = mult(ret, a);
	}
	return ret;
}

long long choose(long long n, long long r){
	//cout << n << " " << r << "\n";
	return mult(fact[n], qikpow(mult(fact[r], fact[n-r]), MOD-2));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> P >> S >> R;
	fact[0] = 1;
	for(int i = 1; i<=10000; i++){
		fact[i] = mult(fact[i-1], i);
	}
	long long ans = 0;
	for(int k = R; k<=S; k++){
		for(int t = 1; t<P; t++){
			long long c = 0;
			if(t*k > S){
				break;
			}
			for(int s = 0; s<=P-t; s++){
				if(t*k+s*k > S){
					break;
				}
				if(s&1){
					c -= mult(choose(S-t*k-s*k+P-t-1, P-t-1), choose(P-t, s));
				}
				else{
					//n might be < 0
					c += mult(choose(S-t*k-s*k+P-t-1, P-t-1), choose(P-t, s));
				}
				c %= MOD;
				c += MOD;
				c %= MOD;
			}
			c = mult(c, choose(P-1, t-1));
			c = mult(c, qikpow(t, MOD-2));
			ans += c;
			ans %= MOD;
		}
		if(k*P == S){
			ans += qikpow(P, MOD-2);
			ans %= MOD;
		}
	}
	//cout << ans << " " << choose(S-R+P-1, P-1) << "\n";
	cout << mult(ans, qikpow(choose(S-R+P-1, P-1), MOD-2));
}