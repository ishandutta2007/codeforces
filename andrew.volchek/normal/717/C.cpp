#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned char ubyte;

const ld EPS = 1e-9;
const ld PI = acos(-1.0);
const int INF = (int)1e9 + 5;
const ll LINF = (ll)1e18 + 5;

bool eq(double a, double b) {
	return fabs(a - b) < EPS;
}

template<class T>
T sqr(const T & x) { return x * x; }

template<class T> 
ll abs(const T & x) { return x < 0 ? -x : x; }

template<class T>
ll myround(const T & x) { return x < 0 ? x - 0.5 : x + 0.5; }

template<class T> 
bool chmin(T & x, const T & y) {
	if (y < x) {
		x = y;
		return true;
	}
	return false;
}

template<class T>
ostream & operator <<(ostream & os, const vector<T> & v) {
	os << "{";
	for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it) {
		os << *it;
		if ((it + 1) != v.end()) os << ", ";
	}
	os << "}";
	return os;
}

template<class P, class Q>
ostream & operator <<(ostream & os, const pair<P, Q> & p) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template<class T> 
bool chmax(T & x, const T & y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

#define all(a) (a).begin(), (a).end()

int main() {
	srand(time(0));
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#else
#endif

	const ll P = 10 * 1000 + 7;

	int n;
	cin >> n;

	vector<ll> a(n);

	for (ll & x : a) {
		cin >> x;
	}

	sort(all(a));

	auto b = a;
	reverse(all(b));

	ll res = 0;

	for (int i = 0; i < n; i++) {
		res = (res + a[i] * b[i]) % P;
	}

	cout << res << endl;

}