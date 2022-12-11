
// Problem : E. Assimilation IV
// Contest : Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1525/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[25][500005];
const long long MOD = 998244353;

long long mult(long long a, long long b){
	return a * b % MOD;
}

long long add(long long a, long long b){
	return (a + b) % MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e / 2);
	ret = mult(ret, ret);
	if(e & 1){
		ret = mult(ret, b);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	long long fact = 1;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> arr[i][j];
		}
		fact *= i;
	}
	long long ans = 0;
	for(int m = 1; m <= M; m++){
		vector<int> fre(N + 2);
		for(int n = 1; n <= N; n++){
			fre[arr[n][m]]++;
		}
		int tot = fre[N + 1];
		long long cnt = 1;
		for(int i = N; i; i--){
			cnt *= tot;
			tot--;
			tot += fre[i];
		}
		ans = add(ans, fact - cnt);
	}
	cout << mult(ans, qikpow(fact % MOD, MOD - 2));
}