
// Problem : E. Baby Ehab Plays with Permutations
// Contest : Codeforces - Codeforces Round #717 (Div. 2)
// URL : https://codeforces.com/contest/1516/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long long dp[405][205][205];
const long long MOD = 1e9+7;
long long fact[505];
long long invfact[505];
long long inv[505];
long long out[505];
long long solve[505];

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
	if(n < r){
		return 0;
	}
	if(solve[r]){
		return solve[r];
	}
	long long ret = 1;
	for(int i = n; i>n-r; i--){
		ret = mult(ret, i);
	}
	ret = mult(ret, invfact[r]);
	return solve[r] = ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	invfact[0] = fact[0] = 1;
	for(int i = 1; i<=500; i++){
		fact[i] = mult(fact[i-1], i);
		inv[i] = qikpow(i, MOD-2);
		invfact[i] = qikpow(fact[i], MOD-2);
	}
	for(int k = 0; k<=K; k++){
		dp[0][k][0] = 1;
	}
	for(int i = 1; i<=2*K; i++){
		for(int j = 1; j<=K; j++){
			for(int k = 1; k<=K; k++){
				long long tot = 1;
				for(int t = 0; t*(j+1)<=i && j*t <= k; t++){
					dp[i][j][k] = add(dp[i][j][k], mult(mult(dp[i-t*(j+1)][j-1][k-j*t], tot), invfact[t]));
					tot = mult(tot, inv[j+1]);
				}
			} 
		}
	}
	for(int k = 0; k<=K; k++){
		long long ans = 0;
		for(int t = 0; t<=min(2*k,N); t++){
			ans = add(ans, mult(fact[t], mult(choose(N, t), dp[t][K][k])));
		}
		out[k] = ans;
		if(k >= 2){
			out[k] = add(out[k], out[k-2]);
		}
		if(k >= 1){
			cout << out[k] << " ";
		}
	}	
}