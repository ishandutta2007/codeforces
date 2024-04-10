// Problem : F. Bingo
// Contest : Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL : https://codeforces.com/contest/1530/problem/F
// Memory Limit : 512 MB
// Time Limit : 7000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[25][25];
const int MOD = 31607;
int dp[25][1 << 21];
int tot[25];

int add(int a, int b){
	return (a + b) % MOD;
}

int sub(int a, int b){
	return ((a - b) % MOD + MOD) %MOD;
}

int mult(int a, int b){
	return (a * b) % MOD;
}

int qikpow(int a, int b){
	if(!b){
		return 1;
	}
	int ret = qikpow(a, b / 2);
	ret = mult(ret, ret);
	if(b&1){
		ret = mult(ret, a);
	}
	return ret;
}

int divd(int a, int b){
	return mult(a, qikpow(b, MOD - 2));
}

int solve(bool d, bool a){
	for(int i = 0; i < N; i++){
		tot[i] = 1;
		for(int j = 0; j < N; j++){
			tot[i] = mult(tot[i], arr[i][j]);
		}
	}
	int ret = 0;
	for(int m = 0; m < (1 << N); m++){
		int val = 1;
		for(int k= 0; k < N; k++){
			int tmp = 1;
			if(!m){
				dp[k][m] = 1;
			}
			else{
				dp[k][m] = mult(dp[k][m^(m&-m)], arr[k][__builtin_ctz(m&-m)]);
			}
			tmp = dp[k][m];
			if(a && !((m>>k)&1)){
				tmp = mult(tmp, arr[k][k]);
			}
			if(d && !((m>>(N-1-k))&1)){
				if(!a || !(N-1-k == k)){
					tmp = mult(tmp, arr[k][N-1-k]);
				}
			}
			val = mult(val, sub(tmp, tot[k]));
		}
 		if(__builtin_popcount(m)&1){
			ret = add(ret, val);
		}
		else{
			ret = sub(ret, val);
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> arr[i][j];
			arr[i][j] = divd(arr[i][j], 10000);
		}
	}
	int ans = solve(0, 0);
	ans = sub(ans, solve(1, 0));
	ans = sub(ans, solve(0, 1));
	ans = add(ans, solve(1, 1));
	cout << add(1, ans) << "\n";
}