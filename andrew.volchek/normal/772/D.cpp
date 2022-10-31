#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = acos(-1.0);
const ll LINF = (ll)1e18 + 5;
const int INF = (int)1e9 + 5;

template<class T>
T sqr(T x) { return x * x; }

template<class T>
T abs(T x) { return x < 0 ? -x : x; }

template<class T>
ll round(T x) { return x < 0 ? x - 0.5 : x + 0.5; }

template<class T>
bool chmin(T & x, const T & y) {
	if (y < x) {
		x = y;
		return true;
	}
	return false;
}

template<class T>
bool chmax(T & x, const T & y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}


template<class P, class Q>
ostream & operator <<(ostream & os, const pair<P, Q> & p) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template<class T>
ostream & operator <<(ostream & os, const vector<T> & v) {
	bool was = false;
	os << "{";
	for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (was) {
			os << ", ";
		}
		else {
			was = true;
		}
		os << *it;
	}
	os << "}";
	return os;
}

template<class T>
ostream & operator <<(ostream & os, const set<T> & v) {
	bool was = false;
	os << "{";
	for (typename set<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (was) {
			os << ", ";
		}
		else {
			was = true;
		}
		os << *it;
	}
	os << "}";
	return os;
}

template<class T>
ostream & operator <<(ostream & os, const multiset<T> & v) {
	bool was = false;
	os << "{";
	for (typename multiset<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (was) {
			os << ", ";
		}
		else {
			was = true;
		}
		os << *it;
	}
	os << "}";
	return os;
}

template<class P, class Q>
ostream & operator <<(ostream & os, const map<P, Q> & v) {
	bool was = false;
	os << "{";
	for (typename map<P, Q>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (was) {
			os << ", ";
		}
		else {
			was = true;
		}
		os << *it;
	}
	os << "}";
	return os;
}

#define all(x) (x).begin(), (x).end()

string nextToken() {
	static char str[(int)1e6 + 5];
	scanf("%s", str);
	return str;
}

template<class T>
T nextInt() {
	ll x = 0;
	bool p = false;
	char c;
	do {
		c = getchar();
	} while (c <= 32);
	if (c == '-') {
		p = true;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return (p ? -x : x);
}

const int LEN = 6;
const ll P = (ll)1e9 + 7;
const int R = (int)1e6;

int pwr10[LEN + 1];

void calcPwr10() {
	pwr10[0] = 1;
	for (int i = 1; i <= LEN; i++) {
		pwr10[i] = pwr10[i - 1] * 10;
	}
}

ll add(ll x, ll y) {
	x += y;
	if (x >= P) x -= P;
	return x;
}

ll sub(ll x, ll y) {
	x += P - y;
	if (x >= P) x -= P;
	return x;
}

ll mul(ll x, ll y) {
	return x * y % P;
}

struct my {
	ll sq, sum, cnt;
	my() {
		sq = 0, sum = 0, cnt = 0;
	}
	my(ll sq, ll sum, ll cnt) : sq(sq), sum(sum), cnt(cnt) {}
	my(int x) : sq(mul(x, x)), sum(x), cnt(1) {}
};

my combine(const my& a, const my& b) {
	my res;
	res.cnt = mul(a.cnt, b.cnt);
	res.sum = (a.sum * b.cnt + b.sum * a.cnt) % P;
	//res.sum = add(mul(a.sum, b.cnt), mul(b.sum, a.cnt));
	//res.sq = add(add(mul(a.sq, b.cnt), mul(b.sq, a.cnt)), mul(mul(a.sum, b.sum), 2));
	res.sq = add((a.sq * b.cnt + b.sq * a.cnt) % P, a.sum * b.sum * 2 % P);

	res.sq = add(res.sq, add(a.sq, b.sq));
	res.sum = add(res.sum, add(a.sum, b.sum));
	res.cnt = add(res.cnt, add(a.cnt, b.cnt));
	return res;
}

int getDigit(int x, int i) {
	return (x / pwr10[i]) % 10;
}

vector<my> calcFirstDP(const vector<int>& a) {
	vector<my> f(R, my()), fn(R, my());
	for (int x : a) {
		f[x] = combine(f[x], my(x));
	}
	for (int pos = 0; pos < LEN; pos++) {
		fill(all(fn), my());
		for (int x = 0; x < R; x++) {
			int curDigit = getDigit(x, pos);
			int newX = x;
			
			for (int toDigit = curDigit; toDigit >= 0; toDigit--) {
				assert(newX <= x);
				fn[newX] = combine(fn[newX], f[x]);
				newX -= pwr10[pos];
			}
		}
		swap(f, fn);
	}
	return f;
}

ostream& operator <<(ostream& os, const my& m) {
	return os << "(" << m.sq << ", " << m.sum << ", " << m.cnt << ")";
}

vector<ll> invDP(vector<ll> f) {
	for (int pos = LEN; pos > 0; pos--) {
		for (int x = R - 1; x >= 0; x--) {
			int curDigit = getDigit(x, pos - 1);
			int newX = x;
			for (int toDigit = curDigit - 1; toDigit >= 0; toDigit--) {
				newX -= pwr10[pos - 1];
				f[newX] = sub(f[newX], f[x]);
			}
		}
	}
	return f;
}

int main(int argc, char * argv[]) {
	srand(time(0));

#ifdef LOCAL
	//gen();
	freopen("input.txt", "r", stdin);
#else
	
#endif
	
	calcPwr10();

	int n;
	scanf("%d", &n);

	vector<int> a(n);

	for (int& x : a) {
		//scanf("%d", &x);
		x = nextInt<int>();
	}
	
	vector<my> dp = calcFirstDP(a);

	vector<ll> f(R);

	for (int i = 0; i < R; i++) {
		f[i] = dp[i].sq;
	}

	f = invDP(f);

	ll res = 0;

	for (int x = 0; x < R; x++) {
		res ^= x * f[x];
	}

	cout << res << endl;
}