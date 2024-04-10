
// Problem : E. Oolimry and Suffix Array
// Contest : Codeforces - Codeforces Round #723 (Div. 2)
// URL : https://codeforces.com/contest/1526/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[200005];
int pos[200005];
const long long MOD = 998244353;

long long mult(long long a, long long b){
	return a * b % MOD;
}

long long fact(int n){
	if(!n){
		return 1;
	}
	return mult(n, fact(n - 1));
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

long long divd(long long a, long long b){
	return mult(a, qikpow(b, MOD - 2));
}

long long choose(long long n, long long r){
	if(n < 0 || n < r || r < 0){
		return 0;
	}
	return divd(fact(n), mult(fact(r), fact(n - r)));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		pos[++arr[i]] = i;
	}
	int must = 0;
	for(int i = 1; i < N; i++){
		if(pos[arr[i] + 1] > pos[arr[i + 1] + 1]){
			must++;
		}
	}
	cout << choose(N + K - 1 - must, N) << "\n";
}