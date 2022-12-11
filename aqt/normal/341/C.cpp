
// Problem : C. Iahub and Permutations
// Contest : Codeforces - Codeforces Round #198 (Div. 1)
// URL : https://codeforces.com/contest/341/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[2005];
bool tkn[2005];
bool pos[2005];
long long fact[2005];
const long long MOD = 1e9+7;

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

long long choose(long long a, long long b){
	return mult(fact[a], qikpow(mult(fact[a-b], fact[b]), MOD-2));
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int K = 0;
	fact[0] = 1;
	for(int i = 1; i<=N; i++){
		fact[i] = mult(fact[i-1], i);
	}
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		if(arr[i]+1){
			tkn[arr[i]] = 1;
			pos[i] = 1;
		}
		else{
			K++;
		}
	}
	int B = 0;
	for(int i = 1; i<=N; i++){
		if(!tkn[i] && !pos[i]){
			B++;
		}
	}
	long long ans = 0;
	for(int i = 0; i<=B; i++){
		if(i%2 == 0){
			ans = add(ans, mult(fact[K-i], choose(B, i)));
		}
		else{
			ans = sub(ans, mult(fact[K-i], choose(B,i)));
		}
	}
	cout << ans;
}