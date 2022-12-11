
// Problem : E. Mocha and Stars
// Contest : Codeforces - Codeforces Round #738 (Div. 2)
// URL : https://codeforces.com/contest/1559/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

using mint = ModularInteger<long long, (long long) 998244353>;

int N, M;
mint dp[100005];
mint pre[100005];
int lft[55], rht[55];
int mob[100005];
bool sieve[100005];

mint f(int l, int r){
	//cout << "Pre: " << l << " " << r << "\n";
	mint ret = 0;
	if(r >= 0){
		ret = pre[r];
	}
	if(l > 0){
		ret -= pre[l-1];
	}
	return ret;
}

mint solve(int k){
	fill(dp, dp+1+M/k, mint(0));
	dp[0] = 1;
	//cout << M << " " << k << " " << M / k << "\n";
	for(int n = 1; n <= N; n++){
		pre[0] = dp[0];
		for(int w = 1; w <= M/k; w++){
			pre[w] = pre[w-1] + dp[w];
		}
		int r = rht[n] / k;
		int l = (lft[n] + k - 1) / k;
		for(int w = 0; w <= M/k; w++){
			dp[w] = f(w-r, w-l);
			//cout << n << " " << w << " " << dp[w] << "\n";
		}
	}
	mint ret = 0;
	for(int w = 0; w <= M/k; w++){
		ret += dp[w];
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	fill(mob+1, mob+1+M, 1);
	for(int i = 2; i <= M; i++){
		if(!sieve[i]){
			for(int j = i; j <= M; j += i){
				mob[j] *= -1;
				sieve[j] = 1;
			}
			for(long long j = 1LL * i * i; j <= M; j += 1LL * i * i){
				mob[j] = 0;
			}
		}
	}
	for(int i = 1; i <= N; i++){
		cin >> lft[i] >> rht[i];
	}
	mint ans = 0;
	for(int m = 1; m <= M; m++){
		if(!mob[m]){
			continue;
		}
		if(mob[m] == 1){
			ans += solve(m);
		}
		else{
			ans -= solve(m);
		}
		//cout << "answer so far: " << m << " " << ans << "\n";
	}
	cout << ans << "\n";
}