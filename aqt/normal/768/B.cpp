
// Problem : B. Code For 1
// Contest : Divide by Zero 2017 and Codeforces Round #399 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/768/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

map<long long, long long> mp;
long long ans = 0;
long long sz = 0;

void rec(long long N, long long l, long long r, long long sz){
	if(N <= 1){
		sz++;
		ans += (N == 1 && l <= sz && r >= sz);
		return;
	}
	if(mp[N/2] + sz >= l && sz <= r){
		rec(N/2, l, r, sz);
	}
	sz += mp[N/2];
	sz++;
	if(l <= sz && sz <= r){
		ans += (N&1);
	}
	if(mp[N/2] + sz >= l && sz <= r){
		rec(N/2, l, r, sz);
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long N, L, R;
	cin >> N >> L >> R;
	long long T = N;
	stack<long long> stk;
	while(T){
		stk.push(T);
		T /= 2;
	}
	long long lst = 1;
	while(stk.size()){
		long long n = stk.top();
		stk.pop();
		mp[n] = lst;
		lst *= 2;
		lst++;
	}
	rec(N, L, R, 0);
	cout << ans << "\n";
}