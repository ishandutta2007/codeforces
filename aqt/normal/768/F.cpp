
// Problem : F. Barrels and boxes
// Contest : Divide by Zero 2017 and Codeforces Round #399 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/768/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int F, W, H;
long long fact[200005];
long long invf[200005];
const long long MOD = 1e9+7;

long long add(long long a, long long b){
	return (a+b)%MOD;
}

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
	//add conditions
	if(r > n || r < 0 || n < 0){
		return 0;
	}
	return mult(fact[n], mult(invf[r], invf[n-r]));	
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> F >> W >> H;
	if(W == 0){
		cout << 1 << "\n";
		return 0;
	}
	if(F == 0){
		cout << (W > H) << "\n";
		return 0;
	}
	int N = F+W;
	fact[0] = 1;
	invf[0] = 1;
	for(int i = 1; i<=N; i++){
		fact[i] = mult(i, fact[i-1]);		
		invf[i] = qikpow(fact[i], MOD-2);
	}
	long long tot = 0;
	for(int i = 1; i<=N; i++){
		tot = add(tot, mult(choose(F-1, i-1), choose(W+1, i)));
	}
	//cout << tot << "\n";
	long long desired = 0;
	for(int k = 1; k<=N; k++){
		long long c = 0;
		c = choose(W-1LL*H*(k-1)-1, k-2);
		c = add(2*choose(W-1LL*H*k-1, k-1), c);
		c = add(choose(W-1LL*H*(k+1)-1, k), c);
		c = mult(c, choose(F-1, k-1));
		desired = add(c, desired);
		//cout << k << endl;
	}
	cout << mult(desired, qikpow(tot, MOD-2)) << "\n";
}