
// Problem : D. Rescue Nibel!
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
priority_queue<pair<int, int>> pq;
long long fact[300005];
long long inv[300005];
long long MOD = 998244353;

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long sub(long long a, long long b){
	a = add(a, -b);
	if(a < 0){
		a += MOD;
	}
	return a;
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
	return mult(fact[n], mult(inv[r], inv[n-r]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	fact[0] = 1;
	inv[0] = 1;
	for(int i=1 ; i<=N; i++){
		int l, r;
		cin >> l >> r;
		pq.push(make_pair(-l, 1));
		pq.push(make_pair(-r, -1));
		fact[i] = mult(fact[i-1], i);
		inv[i] = qikpow(fact[i], MOD-2);
	}
	long long ans = 0;
	int tot = 0;
	while(pq.size()){
		int crnt = pq.top().first;
		int cnt = 0;
		while(pq.size() && pq.top().first == crnt && pq.top().second == 1){
			cnt++;
			pq.pop();
		}
		ans = add(ans, choose(tot+cnt, K));
		ans = sub(ans, choose(tot, K));
		tot += cnt;
		while(pq.size() && pq.top().first == crnt){
			tot--;
			pq.pop();
		}
	}
	cout << ans;
}