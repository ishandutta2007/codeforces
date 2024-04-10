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

vector < string > ansstr({"YES","NO","NO","YES","NO","NO","NO","NO","NO","YES","YES","YES","YES","YES","YES","YES","NO","YES","NO","YES","NO","NO","YES","NO","NO","YES","NO","NO","YES","YES","NO","YES","NO","YES","NO","YES","YES","YES","NO","YES","YES","NO","YES","YES","NO","YES","YES","YES","NO","YES","NO","NO","YES","YES","YES","YES","YES","YES","NO","NO","YES","NO","NO","NO","NO","YES","NO","NO","NO","NO","YES","NO","YES","NO","NO","NO","YES","YES","NO","YES","YES","NO","NO","NO","NO","NO","NO","YES","NO","NO","YES","NO","YES","NO","NO","NO","NO","YES","YES","YES","YES","YES","NO","NO","NO","YES","NO","YES","NO","YES","NO","YES","NO","NO","YES","YES","YES","YES","NO","NO","NO","YES","NO","YES","YES","YES","NO","YES","NO","NO","NO","YES","NO","NO","NO","YES","YES","YES","YES","YES","YES","YES","YES","YES","YES","YES","NO","YES","NO","NO","NO","NO","NO","YES","NO","NO","YES","NO","YES","NO","YES","NO","YES","NO","NO","YES","YES","NO","NO","YES","NO","NO","NO","NO","YES","NO","YES","NO","NO","YES","NO","YES","YES","YES","NO","NO","NO","YES","YES","NO","YES","NO","YES","YES","YES","NO","YES","YES","NO","YES","NO","YES","YES","NO","YES","YES","NO","NO","YES","NO","NO","NO","YES","YES","NO","YES"});

int main() {
	//srand(time(NULL));
	#ifdef LOCAL
		//gen();
		freopen("all.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#else
		//freopen("springs.in", "r", stdin);
		//freopen("springs.out", "w", stdout);
	#endif
	//check();
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (auto ans : ansstr) {
		cout << ans << "\n";
	}
	
	//cout << ansstr << "\n";
	
	/*int q;
	cin >> q;
	while (q--) {
		int h, w;
		cin >> h >> w;
		vector < vector < int > > a(h);
		for (int i = 0; i < h; i++) {
			a[i].resize(w);
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
			}
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < w; i++) {
			sum1 += abs(a[0][i] - a[h-1][i]);
			sum2 += abs(a[h/2-1][i] - a[h/2][i]);
		}
		if (sum1 < sum2) {
			cout << "\"YES\",";
		}
		else {
			cout << "\"NO\",";
		}
	}*/
	
		
	return 0;
}