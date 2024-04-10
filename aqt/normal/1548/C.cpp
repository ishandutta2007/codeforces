
// Problem : C. The Three Little Pigs
// Contest : Codeforces - Codeforces Round #736 (Div. 1)
// URL : https://codeforces.com/contest/1548/problem/C
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

template <class T, const T MOD> struct ModularInteger{	
	T v;
	
	ModularInteger(T x = 0) {
		v = x % MOD;
		if(v < 0){
			v += MOD;
		}
	}
	
	ModularInteger & operator += (const ModularInteger & u) {
		v = (v + u.v) % MOD;
		return *this;
	}
	
	ModularInteger & operator -= (const ModularInteger & u) {
		v = ((v - u.v) % MOD + MOD) % MOD;
		return *this;
	}
	
	ModularInteger & operator *= (const ModularInteger & u) {
		v = v * u.v % MOD;
		return *this;
	}
	
	ModularInteger & operator /= (const ModularInteger & u) {
		return *this *= u.inverse();
	}
	
	ModularInteger operator - () const {
		return ModularInteger(- v);
	}
	
	ModularInteger operator + (const ModularInteger & u) const {
		return ModularInteger(v) += u.v;
	}
	
	ModularInteger operator - (const ModularInteger & u) const {
		return ModularInteger(v) -= u.v;
	}
	
	ModularInteger operator * (const ModularInteger & u) const {
		return ModularInteger(v) *= u.v;
	}
	
	ModularInteger operator / (const ModularInteger & u) const {
		return ModularInteger(v) /= u.v;
	}
	
	ModularInteger inverse() const {
		T a = v, b = MOD, x = 1, y = 0;
		while(b > 0){
			T t = a / b;
			swap(a -= t * b, b);
			swap(x -= t * y, y);
		}
		return ModularInteger(x);
	}
	
	ModularInteger pow(long long e) const {
		ModularInteger ret = 1, mul = v;
		while(e > 0){
			if(e & 1){
				ret *= mul;
			}
			mul *= mul;
			e >>= 1;
		}
		return ret;
	}
	
	bool operator == (const ModularInteger & p) const { 
		return v == p.v; 
	}
	
	bool operator != (const ModularInteger & p) const { 
		return v != p.v; 
	}
	
	friend ostream & operator << (ostream & os, const ModularInteger & o){
		return os << o.v;
	}
	
	friend istream & operator >> (istream & is, ModularInteger & i){
		T t;
		cin >> t;
		i = ModularInteger<T, MOD>(t);
		return is;
	}
};

using mint = ModularInteger<long long, (long long) 1000000007>;

const int M = 3000005;
const mint inv3 = mint(1) / mint(3);
mint fact[3000005];
mint inv[3000005];
mint ans[3000005];
int N, Q;

mint choose(int n, int r){
	if(r > n){
		return 0;
	}
	return fact[n] * inv[r] * inv[n - r];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	fact[0] = 1;
	for(int i = 1; i < M; i++){
		fact[i] = fact[i-1] * i;
	}
	inv[M - 1] = mint(1) / fact[M - 1];
	for(int i = M - 2; i >= 0; i--){
		inv[i] = inv[i + 1] * (i + 1);
	}
	ans[0] = N+1;
	ans[1] = 1LL * N * (3 * N + 3) / 2;
	for(int i = 2; i <= 3 * N; i++){
		ans[i] = (choose(3 * N + 3, i + 1) - ans[i - 1] * 3 - ans[i - 2]) * inv3;
	}
	while(Q--){
		int n;
		cin >> n;
		cout << ans[n] << "\n";
	}
}