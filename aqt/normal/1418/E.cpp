
// Problem : E. Expected Damage
// Contest : Codeforces - Educational Codeforces Round 95 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1418/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[200005];
long long pre[200005];
const long long MOD = 998244353;

long long mult(long long a, long long b){
	return a*(b%MOD)%MOD;
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

long long add(long long a, long long b){
	return (a+b)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 0; i<N; i++){
		cin >> arr[i];
	}
	sort(arr, arr+N);
	for(int i= 0; i<N; i++){
		pre[i+1] = arr[i] + pre[i];
	}
	while(M--){
		int k, v;
		cin >> k >> v;
		int idx = lower_bound(arr, arr+N, v) - arr;
		int cnt = N - idx;
		if(k > cnt){
			cout << 0 << "\n";
		}
		else{
			long long ans = mult(mult(cnt - k, qikpow(cnt, MOD-2)), pre[N] - pre[idx]);
			ans = add(ans, mult(mult(cnt-k+1, qikpow(cnt+1, MOD-2)), pre[idx]));
			cout << ans << "\n";
		}
	}
}