
// Problem : E. You
// Contest : Codeforces - Codeforces Round #735 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1554/E
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

template <class T, const T MOD> struct ModularInteger{	
	T v;
	
	ModularInteger(T x = 0) {
		v = x;
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

int T, N;
vector<int> fct[100005];
vector<int> graph[100005];
mint out[100005];

int dfs(int n, int p, int k){
	int cnt = 0;
	for(int e : graph[n]){
		if(e != p){
			int res = dfs(e, n, k);
			if(res == 2){
				return 2;
			}
			cnt += res;
		}
	}
	if(cnt%k == 0){
		return 1;
	}
	else if((cnt + 1) % k == 0 && p){
		return 0;
	}
	else{
		return 2;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j += i){
			fct[j].emplace_back(i);
		}
	}
	while(T--){
		cin >> N;
		for(int i = 1; i <= N; i++){
			graph[i].clear();
			out[i] = 0;
		}
		for(int i = 1; i < N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].emplace_back(b);
			graph[b].emplace_back(a);
		}
		out[1] = mint(2).pow(N - 1);
		for(int f = 2; f <= N; f++){
			if((N - 1) % f == 0){
				int res = dfs(1, 0, f);
				if(res == 1){
					out[f] = res;
				}
			}
		}
		for(int f = N; f; f--){
			for(int k = 2 * f; k <= N; k += f){
				out[f] -= out[k];
			}
		}
		for(int f = 1; f <= N; f++){
			cout << out[f] << " ";
		}
		cout << "\n";
	}
}