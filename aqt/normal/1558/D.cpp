
// Problem : D. Top-Notch Insertions
// Contest : Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL : https://codeforces.com/contest/1558/problem/D
// Memory Limit : 512 MB
// Time Limit : 3000 ms
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

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

struct node{
	long long v;
	long long s;
	int pri;
	long long lzy;
	bool lzyr;
	int sz;
	node * c[2];
	node (long long _v){
		s = v = _v;
		pri = uniform_int_distribution<int> (INT_MIN, INT_MAX) (g1);
		lzy = 0;
		c[0] = c[1] = NULL;
		sz = 1;
	}
};

node * treap;

long long getsum(node * n){
	return n ? n->s : 0;
}

int getsz(node * n){
	return n ? n->sz : 0;
}

node * pd(node * n){
	if(n->lzyr){
		for(int k = 0; k<2; k++){
			if(n->c[k]){
				n->c[k]->lzyr = 1;
				n->c[k]->lzy = 0;
				n->c[k]->v = n->c[k]->s = 0;
			}
		}
	}
	if(n->lzy){
		for(int k = 0; k<2; k++){
			if(n->c[k]){
				n->c[k]->lzy += n->lzy;
				n->c[k]->s += n->lzy * n->c[k]->sz;
				n->c[k]->v += n->lzy;
			}
		}
	}
	n->lzy = 0;
	n->lzyr = 0;
	return n;
}

node * pu(node * n){
	n->sz = getsz(n->c[0]) + getsz(n->c[1]) + 1;
	n->s = n->v + getsum(n->c[0]) + getsum(n->c[1]);
	return n;
}

pair<node *, node *> split(node * n, long long k){
	if(!n){
		return {n, n};
	}
	n = pd(n);
	if(n->v >= k){
		auto p = split(n->c[0], k);
		n->c[0] = p.second;
		return {p.first, pu(n)};
	}
	else{
		auto p = split(n->c[1], k);
		n->c[1] = p.first;
		return {pu(n), p.second};
	}
}

pair<node *, node *> splitsz(node * n, int k){
	if(!n){
		return {n, n};
	}
	n = pd(n);
	if(getsz(n->c[0]) >= k){
		auto p = splitsz(n->c[0], k);
		n->c[0] = p.second;
		return {p.first, pu(n)};
	}
	else{
		auto p = splitsz(n->c[1], k-getsz(n->c[0])-1);
		n->c[1] = p.first;
		return {pu(n), p.second};
	}
}

node * merge(node * lft, node * rht){
	if(!lft){
		return rht;
	}
	if(!rht){
		return lft;
	}
	lft = pd(lft);
	rht = pd(rht);
	node * n;
	if(lft->pri > rht->pri){
		lft->c[1] = merge(lft->c[1], rht);
		n = lft;
	}
	else{
		rht->c[0] = merge(lft, rht->c[0]);
		n = rht;
	}
	return pu(n);
}

void traverse(node * n){
	if(!n){
		return;
	}
	pd(n);
	traverse(n->c[0]);
	cout << n->v << " ";
	traverse(n->c[1]);
}

int T, N, M;
mint fact[400005];

mint choose(long long n, long long r){
	if(r > n || r < 0){
		return 0;
	}
	return fact[n] / (fact[r] * fact[n-r]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	fact[0] = 1;
	for(int i = 1; i <= 400000; i++){
		fact[i] = fact[i-1] * i;
	}
	while(T--){
		cin >> N >> M;
		treap = nullptr;
		while(M--){
			int x, y;
			cin >> x >> y;
			pair<node *, node *> splitaty = split(treap, y);
			bool addin = 0;
			if(getsz(splitaty.second) >= 1){
				pair<node *, node *> splitagainpair = splitsz(splitaty.second, 1);
				if(splitagainpair.first->v != y){
					addin = 1;
				}
				splitaty.second = merge(splitagainpair.first, splitagainpair.second);
			}
			else{
				addin = 1;
			}
			if(addin){
				splitaty.second = merge(new node(y), splitaty.second);
			}
			splitaty.second->lzy++;
			splitaty.second->v++;
			treap = merge(splitaty.first, splitaty.second);
		}
		cout << choose(N + N - 1 - getsz(treap), N) << "\n";
	}
}