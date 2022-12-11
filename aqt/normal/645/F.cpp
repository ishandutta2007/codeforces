
// Problem : F. Cowslip Collections
// Contest : Codeforces - CROC 2016 - Elimination Round
// URL : https://codeforces.com/contest/645/problem/F
// Memory Limit : 512 MB
// Time Limit : 8000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, Q;
const int M = 1e6;
vector<int> divs[M+5];
const long long MOD = 1e9+7;
long long fact[1000005];
long long contr[1000005];
long long choose[1000005];
bool sieve[1000005];
int mob[1000005];
int fre[1000005];

long long mult(long long a, long long b){
	return a * b % MOD;
}

long long add(long long a, long long b){
	return (a + b) % MOD;
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
	if(e & 1){
		ret = mult(ret, b);
	}
	return ret;
}

long long divd(long long a, long long b){
	return mult(a, qikpow(b, MOD - 2));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> Q;
	for(int i = 1; i <= M; i++){
		for(int j = i; j <= M; j += i){
			divs[j].emplace_back(i);
		}
	}
	fact[0] = 1;
	for(int i = 1; i <= M; i++){
		fact[i] = mult(fact[i-1], i);
	}
	fill(mob, mob + M + 1, 1);
	for(int i = 2; i <= M; i++){
		if(!sieve[i]){
			for(int j = i; j <= M; j += i){
				mob[j] *= -1;
				sieve[j] = 1;
			}
			for(long long j = 1LL * i * i; j <= M; j += i * i){
				mob[j] = 0;
			}
		}
		if(mob[i] == -1){
			mob[i] = MOD-1;
		}
	}
	for(int i = 1; i <= M; i++){
		for(int j = 1; i * j <= M; j++){
			contr[i * j] = add(contr[i * j], mult(mob[j], i));
		}
	}
	for(int i = 1; i <= N; i++){
		int n;
		cin >> n;
		for(int f : divs[n]){
			fre[f]++;
		}
	}
	long long ans = 0;
	for(int i = K; i <= M; i++){
		choose[i] = divd(fact[i], mult(fact[i-K], fact[K]));
	}
	for(int i = 1; i <= M; i++){
		ans = add(ans, mult(contr[i], choose[fre[i]]));
	}
	while(Q--){
		int n;
		cin >> n;
		for(int f : divs[n]){
			ans = sub(ans, mult(contr[f], choose[fre[f]]));
			fre[f]++;
			ans = add(ans, mult(contr[f], choose[fre[f]]));
		}
		cout << ans << "\n";
	}
}