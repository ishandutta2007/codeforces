
// Problem : E. Phoenix and Computers
// Contest : Codeforces - Codeforces Global Round 14
// URL : https://codeforces.com/contest/1515/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long MOD;
long long fact[405];
long long finv[405];
long long inv[405];
long long dp[405][405];
long long pows[405];

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return (a * b)%MOD;
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
	cin >> N >> MOD;
	N++;
	fact[0] = finv[0] = 1;
	pows[0] = 1;
	for(int i = 1; i <= N; i++){
		fact[i] = mult(fact[i-1], i);
		finv[i] = qikpow(fact[i], MOD - 2);
		inv[i] = qikpow(i, MOD - 2);
		pows[i] = mult(pows[i-1], 2);
	}
	dp[0][0] =1;
	for(int i =1; i <=N; i++){
		for(int k = 1; k <= i; k++){
			for(int l = 1; l <= i; l++){
				if(k >= l && i - l - 1 >= 0){
					dp[i][k] = add(dp[i][k], mult(finv[l], mult(dp[i - l - 1][k - l], pows[l-1])));
				}
			}
		}
	}
	long long ans = 0;
	for(int k = 1; k <= N; k++){
		ans = add(ans, mult(fact[k], dp[N][k]));
	}
	cout << ans;
	/*
	if(N == 1){
		cout << 1 << "\n";
		return 0;
	}
	else if(N == 2){
		cout << 2 << "\n";
		return 0;
	}
	else if(N == 3){
		cout << 6 << "\n";
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= N; i++){
		for(int k = 1; k <= i; k++){
			for(int l = 1; l <= i; l++){
				if(k >= l && i - l - 1 >= 0){
					dp[i][k] = add(dp[i][k], mult(dp[i - l - 1][k - l], mult(finv[l], pows[l-1])));						
				}
			}
		}
	}

	//cout << dp[1][1] << endl;
	long long ans = 0;
	for(int i = 0; i <= N; i++){
		ans = add(ans, mult(fact[N-1], mult(finv[i-1], finv[N-i])));
	}
	for(int p = 1; p <= N; p++){
		for(int s = 1; s + p < N; s++){
			for(int k = 0; s + p + k + 1 <= N; k++){
				long long tot = mult(mult(finv[s], finv[p]), mult(fact[s + p + k], dp[N - s - p - 1][k]));
				//cout << mult(finv[s], finv[p]) << " " << N - s - p - 1 << " " << k << "\n";
				//cout << dp[N - s - p - 1][k] << "\n";
				if(p == 2 && s == 2){
					tot = add(tot, mult(3, mult(mult(finv[s], finv[p]), mult(fact[s + p + k], dp[N - s - p - 1][k]))));
				}
				else if(p == 2){
					tot = add(tot, mult(mult(finv[s], finv[p]), mult(fact[s + p + k], dp[N - s - p - 1][k])));
					if(s > 1){
						tot = add(tot, mult(mult(finv[s-1], 2 * finv[p]), mult(fact[s + p + k], dp[N - s - p - 1][k])));
					}
				}
				else if(s == 2){
					tot = add(tot, mult(mult(finv[s], finv[p]), mult(fact[s + p + k], dp[N - s - p - 1][k])));
					if(p > 1){
						tot = add(tot, mult(mult(2 * finv[s], finv[p-1]), mult(fact[s + p + k], dp[N - s - p - 1][k])));
					}
				}
				else{
					if(p > 1){
						tot = add(tot, mult(mult(finv[s], finv[p-1]), mult(fact[s + p + k], dp[N - s - p - 1][k])));
					}
					if(s > 1){
						tot = add(tot, mult(mult(finv[s-1], finv[p]), mult(fact[s + p + k], dp[N - s - p - 1][k])));
					}
					if(p > 1 && s > 1){
						tot = add(tot, mult(mult(finv[s-1], finv[p-1]), mult(fact[s + p + k], dp[N - s - p - 1][k])));
					}
				}
				cout << p << " " << s << " " << k << " " << tot << "\n";
				ans = add(ans, tot);
			}
		}
	}
	cout << ans << "\n";
	*/
	/*
	if(N == 1){
		cout << 1 << "\n";
		return 0;
	}
	else if(N == 2){
		cout << 2 << "\n";
		return 0;
	}
	else if(N == 3){
		cout << 6 << "\n";
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= N; i++){
		for(int k = 1; k <= i; k++){
			for(int l = 1; l < i; l++){
				if(k >= l && i - l - 1 != 0){
					//long long coe = (l == 1 ? 1 : 2);
					if(i == N){
						if(l == 1){
							dp[i][k] = add(dp[i][k], dp[i - l - 1][k - 1]);
						}
						else if(l == 2){
							dp[i][k] = add(dp[i][k], dp[i - l - 1][k - 2]);
						}
						else{
							long long bad = qikpow(l, MOD - 2);
							dp[i][k] = add(dp[i][k], mult(dp[i - l - 1][k - l], 
							add(finv[l], finv[l-1])));	
						}
					}
					else{
						dp[i][k] = add(dp[i][k], mult(dp[i - l - 1][k - l], mult(finv[l], (l == 1 ? 1 : 2))));						
					}
				}
			}
			//make sure l = i case
			if(k >= i){
				if(i == N){
					long long bad = qikpow(i, MOD - 2);
					//cout << add(2, mult(2, mult(bad, mult(i-1, finv[i-1])))) << endl;
					dp[i][k] = add(dp[i][k], mult(dp[0][k - i], 
					mult(2, mult(bad, mult(i-1, finv[i-1])))));
				}
				else{
					long long bad = qikpow(i, MOD - 2);
					dp[i][k] = add(dp[i][k], mult(dp[0][k - i], 
					add(mult(finv[i], (i <= 1 ? 1 : 2)), mult(bad, mult(finv[i-1], i-1)))));
					//dp[i][k] = add(dp[i][k], add(finv[i], finv[i-1]));
				}
			}
			cout << i << " " << k << " " << dp[i][k] << endl;
		}
	}
	long long ans = 0;
	for(int i = 1; i <= N; i++){
		cout << mult(fact[i], dp[N][i]) << endl;
		//cout << dp[N][i] << endl;
		ans = add(ans, mult(fact[i], dp[N][i]));
	}
	cout << add(2, ans);
	*/
}