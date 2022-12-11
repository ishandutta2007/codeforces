
// Problem : F. Sports Betting
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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

int N;
mint arr[15];
mint dp[1<<15];
mint cst[15][15];
mint mskcst[15][1<<15];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i != j){
				cst[i][j] = arr[i] / (arr[i] + arr[j]);
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int m = 0; m < (1 << N); m++){
			if(m>>i&1){
				continue;
			}
			mskcst[i][m] = 1;
			for(int k = 0; k < N; k++){
				if(m>>k&1){
					mskcst[i][m] *= cst[i][k];
				}
			}
		}
	}
	for(int m = 1; m < (1<<N); m++){
		mint sum = 0;
		for(int t = m; t; t = (m&(t-1))){
			mint tot = dp[t];
			for(int k = 0; k < N; k++){
				if(t>>k&1){
					tot *= mskcst[k][m^t];
				}
			}
			sum += tot;
		}
		dp[m] = mint(1) - sum;
	}
	mint ans = 0;
	for(int m = 1; m < (1<<N); m++){
		mint tot = dp[m] * __builtin_popcount(m);
		for(int k = 0; k < N; k++){
			if(m>>k&1){
				tot *= mskcst[k][((1<<N)-1)^m];
			}
		}
		ans += tot;
	}
	cout << ans << "\n";
}