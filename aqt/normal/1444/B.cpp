
// Problem : B. Divide and Sum
// Contest : Codeforces - Codeforces Round #680 (Div. 1, based on Moscow Team Olympiad)
// URL : https://codeforces.com/contest/1444/problem/B
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[300005];
const long long MOD = 998244353;

long long add(long long a, long long b){
	return (a+b)%MOD;
}

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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=2*N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+2*N);
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		ans = add(ans, mult(MOD-1, arr[i]));
	}
	for(int i = N+1; i<=2*N; i++){
		ans = add(ans, arr[i]);
	}
	for(int i = N+1; i<=2*N; i++){
		ans = mult(ans, i);
	}
	for(int i = 1; i<=N; i++){
		ans = mult(ans, qikpow(i, MOD-2));
	}
	cout << ans;
}