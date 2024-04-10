
// Problem : F. Expected Square Beauty
// Contest : Codeforces - Educational Codeforces Round 67 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1187/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int l[200005];
int r[200005];
const long long MOD = 1e9+7;
long long pre[200005];
long long suf[200005];
long long sp[200005];

long long add(long long a, long long b){
	return (a + b) % MOD;
}

long long mult(long long a, long long b){
	return a * b %MOD;
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

long long sqr(long long x){
	return mult(x, x);
}

long long sub(long long a, long long b){
	return add(MOD, add(a, -b));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> l[i];
	}
	for(int i = 1; i <= N; i++){
		cin >> r[i];
	}
	long long ans = 1;
	for(int i = 2; i <= N; i++){
		int mn = max(l[i], l[i-1]), mx = min(r[i], r[i-1]);
		int rng = mx >= mn ? mx - mn + 1 : 0;
		long long p = mult(rng, mult(qikpow(r[i] - l[i] + 1, MOD - 2), qikpow(r[i-1] - l[i-1] + 1, MOD - 2)));
		ans = add(ans, sub(1, p));
		sp[i] = pre[i] = suf[i] = p;
		ans = add(ans, mult(2, sub(1, p)));
	}	
	for(int i = 2; i <= N; i++){
		pre[i] = add(pre[i-1], sub(1, sp[i]));
	}
	for(int i = N; i; i--){
		suf[i] = add(suf[i + 1], sub(1, sp[i]));
	}
	for(int i = 2; i <= N; i++){
		ans = add(ans, mult(sub(1, sp[i]), add(pre[i - 2], suf[i + 2])));
	}
	for(int i = 2; i < N; i++){
		int mn = max({l[i-1], l[i], l[i+1]}), mx = min({r[i-1], r[i], r[i+1]});
		int rng = mx >= mn ? mx - mn + 1 : 0;
		int mn1 = max(l[i-1], l[i]), mx1 = min(r[i-1], r[i]);
		int rng1 = mx1 >= mn1 ? mx1 - mn1 + 1 : 0;
		int mn2 = max(l[i+1], l[i]), mx2 = min(r[i+1], r[i]);
		int rng2 = mx2 >= mn2 ? mx2 - mn2 + 1 : 0;
		int num = mult(r[i] - l[i] + 1, mult(r[i-1] - l[i-1] + 1, r[i+1]-l[i+1] + 1));
		num = add(sub(num, add(mult(rng1, r[i+1] - l[i+1] + 1), mult(rng2, r[i-1] - l[i-1] + 1))), rng);
		long long p = mult(num, mult(mult(qikpow(r[i-1]-l[i-1]+1,MOD-2), qikpow(r[i]-l[i]+1, MOD-2)), qikpow(r[i+1]-l[i+1]+1,MOD-2)));
		ans = add(ans, mult(2, p));
	}
	cout << ans;
}