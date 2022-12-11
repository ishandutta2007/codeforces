
// Problem : C. Bargain
// Contest : Codeforces - Codeforces Round #675 (Div. 2)
// URL : https://codeforces.com/contest/1422/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

string s;
long long pows[100005];
long long pre[100005];
const long long MOD = 1e9+7;

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long sub(long long a, long long b){
	a = add(a, -b);
	if(a < 0){
		a += MOD;
	}
	return a;
}

long long qikpow(long long a, long long b){
	if(!b){
		return 1;
	}
	long long ret = qikpow(a, b/2);
	ret = mult(ret, ret);
	if(b&1){
		ret = mult(ret, a);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	pows[0] = 1;
	int N = s.size();
	for(int i = 1; i<=N; i++){
		pre[i] = add(mult(pre[i-1], 10), s[i-1]-'0');
		pows[i] = mult(pows[i-1], 10);
	}
	long long ans = mult(pre[N], mult(qikpow(2, MOD-2), mult(N, N+1)));
	/*
	for(int i = 1; i<=N; i++){
		//ans = add(ans, mult(N-i+1, mult(pre[N], qikpow(pows[i-1], MOD-2))));
		ans = add(ans, mult(pre[i-1], N-i+1));
		//long long g = mult(10, mult(sub(pows[i], 1), qikpow(9, MOD-2)));
		//ans = sub(ans, mult(g, mult(mult(pre[i], pows[N-i]), qikpow(pows[i], MOD-2))));
		long long g = mult(sub(pows[i], 1), qikpow(9, MOD-2));
		cout << ans << "\n";
		ans = add(ans, mult(pre[N], g));
		cout << "bang: " << mult(pre[N], g) << "\n";
		cout << ans << "\n";
		ans = sub(ans, mult(g, mult(pre[i], pows[N-i])));
		cout << "bing: " << mult(g, mult(pre[i], pows[N-i])) << "\n";
		cout << ans << "\n";
	}
	*/
	for(int i = 1; i<=N; i++){
		long long g = mult(sub(pows[N-i+1], 1), qikpow(9, MOD-2));
		ans = add(ans, mult(pre[i-1], g));
		ans = sub(ans, mult(i, mult(pre[i], pows[N-i])));
	}
	cout << ans;
}