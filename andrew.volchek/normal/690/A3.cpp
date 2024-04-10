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
	os << "{";
	bool was = false;
	for (const T & x : v) {
		if (was) {
			os << ", ";
		}
		was = true;
		os << x;
	}
	os << "}";
	return os;
}

template<class T>
ostream & operator <<(ostream & os, const set<T> & v) {
	os << "{";
	bool was = false;
	for (const T & x : v) {
		if (was) {
			os << ", ";
		}
		was = true;
		os << x;
	}
	os << "}";
	return os;
}

template<class P, class Q>
ostream & operator <<(ostream & os, const map<P, Q> & m) {
	os << "{";
	bool was = false;
	for (const auto & x : m) {
		if (was) {
			os << ", ";
		}
		was = true;
		os << x;
	}
	os << "}";
	return os;
}

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
	#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#else
	#define DEBUG(X) {}
#endif

void solve() {
	int n, r;
	scanf("%d%d", &n, &r);
	r--;
	for (int i = 0; i < n - 1; i++) {
		int x;
		scanf("%d", &x);
		r -= x;
	}
	r %= n;
	while (r <= 0) r += n;
	printf("%d\n", r);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#else

#endif

	int T;
	scanf("%d", &T);

	while (T--) {
		solve();
	}
		
}