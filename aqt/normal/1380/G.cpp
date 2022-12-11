
// Problem : G. Circular Dungeon
// Contest : Codeforces - Educational Codeforces Round 91 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1380/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[300005];
long long pre[300005];
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
	for(int i= 1; i<=N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+N, greater<long long>());
	partial_sum(arr, arr+1+N, pre);
	const long long denom = qikpow(N, MOD-2);
	for(int i = 1; i<=N; i++){
		long long ans = 0;
		for(int x = 0; x*i<N; x++){
			ans = add(ans, mult(x, pre[min(N, x*i+i)] - pre[x*i]));
		}
		cout << mult(ans, denom) << " ";
	}
}