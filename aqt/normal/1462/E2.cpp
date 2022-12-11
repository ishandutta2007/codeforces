
// Problem : E2. Close Tuples (hard version)
// Contest : Codeforces - Codeforces Round #690 (Div. 3)
// URL : https://codeforces.com/contest/1462/problem/E2
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, M, K;
int arr[200005];
long long fact[200005];
const long long MOD = 1000000007;

long long mult(long long a, long long b){
	return a*b%MOD;
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
	if(r > n){
		return 0;
	}
	return mult(fact[n], qikpow(mult(fact[r], fact[n-r]), MOD-2));
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	fact[0] = 1;
	for(int i =1 ; i<=200000; i++){
		fact[i] = mult(fact[i-1], i);
	}
	while(T--){
		cin >> N >> M >> K;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		sort(arr+1, arr+1+N);
		long long ans = 0;
		for(int r = 1, l = 1; r<=N; r++){
			while(arr[r] - arr[l] > K){
				l++;
			}
			ans = add(ans, choose(r - l, M - 1));
		}
		cout << ans << "\n";
	}
}