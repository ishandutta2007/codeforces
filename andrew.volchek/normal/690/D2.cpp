#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <fstream>
#include <stack>

using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double

template<typename T>
T abs(T x) {
	return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
	return x * x;
}

template<typename T>
ostream& operator << (ostream &s, const vector<T> &x) {
	s << "[";
	for (auto it : x) {
		s << it << ", ";
	}
	s << "]";
	return s;
}

template<typename T>
ostream& operator << (ostream &s, const set<T> &x) {
	s << "{";
	for (auto it : x) {
		s << it << ", ";
	}
	s << "}";
	return s;
}


template<typename U, typename V>
ostream& operator << (ostream &s, const pair<U, V> &x) {
	s << "(" << x.fst << ", " << x.snd << ")";
	return s;
}

template<typename T>
bool chmax(T &x, const T &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

template<typename T>
bool chmin(T &x, const T &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

//---------------------------------------------------------------------

const ll MOD = 1e6 + 3;
const int maxn = 1e6 + 2;
ll fact[maxn], inv[maxn];

ll binpow(ll x, ll st, ll mod) {
	ll ans = 1;
	while (st) {
		if (st & 1) {
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
		st >>= 1;
	}
	return ans;
}

ll getc(ll n, ll k) {
	return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main() {
	//srand(time(NULL));
	#ifdef LOCAL
		//gen();
		freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#else
		//freopen("springs.in", "r", stdin);
		//freopen("springs.out", "w", stdout);
	#endif
	//check();
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 2; i * i <= MOD; i++) {
		if (MOD % i == 0) {
			cout << i << "\n";
		}
	}
	
	fact[0] = inv[0] = 1;
	
	for (int i = 1; i < maxn; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		inv[i] = binpow(fact[i], MOD - 2, MOD);
	}
	
	
	int n, c;
	cin >> n >> c;
	cout << getc(n + c, c) - 1 << "\n";
	
	return 0;
}