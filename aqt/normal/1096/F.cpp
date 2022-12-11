
// Problem : F. Inversion Expectation
// Contest : Educational Codeforces Round 57 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1096/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
int bit[200005];
int cnt[200005];
int open[200005];
long long fact[200005];
const long long MOD = 998244353;

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return (a*b)%MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e>>1);
	ret = mult(ret,ret);
	if(e&1){
		ret = mult(ret, b);
	}
	return ret;
}

long long divd(long long a, long long b){
	return mult(a, qikpow(b, MOD-2));
}

void upd(int n){
	while(n <= N){
		bit[n]++;
		n += n&-n;
	}
}

int query(int n){
	int ret = 0;
	while(n){
		ret += bit[n];
		n -= n&-n;
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	fact[0] = 1;
	for(int i = 1; i<=N; i++){
		fact[i] = mult(fact[i-1], i);
	}
	long long init = 0;
	int missing = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		if(arr[i] > 0){
			init += query(N)-query(arr[i]);
			upd(arr[i]);
			cnt[arr[i]] = 1;
		}
		else{
			missing++;
			open[i]++;
		}
	}
	if(missing == 0){
		cout << init%MOD << "\n";
		return 0;
	}
	init%= MOD;
	long long tot = divd(mult(fact[missing],mult(missing-1, missing)), 4);
	//cout << init << "\n";
	for(int i = 1; i<=N; i++){
		cnt[i] ^= 1;
		cnt[i] += cnt[i-1];
		open[i] += open[i-1];
	}
	for(int i = 1; i<=N; i++){
		if(arr[i] > 0){
			int less = cnt[arr[i]];
			int rht = open[N] - open[i];
			tot = add(tot, mult(mult(less, rht), fact[missing-1]));
			int great = missing - less;
			int lft = open[i];
			tot = add(tot, mult(mult(great, lft), fact[missing-1]));
		}
	}
	//cout << tot <<"\n";
	cout << add(init, divd(tot, fact[missing])) <<"\n";
}