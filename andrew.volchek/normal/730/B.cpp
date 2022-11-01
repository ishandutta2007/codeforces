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

string nextToken() {
	static char str[200200];
	scanf("%s", str);
	return str;
}

int iter = 0;

char ask(int x, int y) {
	cout << "? " << x << " " << y << "\n";
	fflush(stdout);
	char resp = '<';
	cin >> resp;
	return resp;
}

int getMax(int x, int y) {
	char c = ask(x, y);
	if (c == '>') return x;
	return y;
}

int getMin(int x, int y) {
	char c = ask(x, y);
	if (c == '<') return x;
	return y;
}

pair<int, int> combine(const pair<int, int> & a, const pair<int, int> & b) {
	return make_pair(getMin(a.first, b.first), getMax(a.second, b.second));
}

vector<pair<int, int>> z;

pair<int, int> rec(int l, int r) {
	if (l == r) return z[l];
	int m = (l + r) >> 1;
	return combine(rec(l, m), rec(m + 1, r));
}

pair<int, int> foo(pair<int, int> a) {
	if (a.first == a.second) return a;
	if (ask(a.first, a.second) == '<') return a;
	return make_pair(a.second, a.first);
}

void solve() {
	z.clear();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i += 2) {
		int nxt = min(i + 1, n);
		z.push_back(make_pair(i, nxt));
		z.back() = foo(z.back());
	}
	auto t = rec(0, (int)z.size() - 1);
	cout << "! " << t.first << " " << t.second << "\n";
	fflush(stdout);
}

int main() {
	srand(time(0));

#ifdef LOCAL
	//gen();
	//freopen("input.txt", "r", stdin);
#else
	
#endif

	int t = 1;
	cin >> t;
	while (t--) solve();
	
}