#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <fstream>

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

ll gcd(ll x, ll y) {
	while (x && y) {
		if (x > y) x %= y;
		else y %= x;
	}
	return x + y;
}

bool inRange(ll l, ll r, ll x) { return
	x >= l && x <= r; }

bool can(ll x, ll y, ll p, ll q) { 
	if (x > p) return false;
	if (y > q) return false;
	ll remQ = q - y;
	ll remP = p - x;
	if (remP > remQ) return false;
	return true;
}

ll foo(ll x, ll y, ll p, ll q) { return q - y; }

ll go(ll x, ll y, ll p, ll q) {
	ll l = 0, r = LINF / q + 1;
	while (r - l > 1) {
		ll mid = (l + r) >> 1;
		if (can(x, y, p * mid, q * mid)) r = mid;
		else l = mid;
	}
	ll mid = r;
	if (!can(x, y, p * mid, q * mid)) return -1;
	return foo(x, y, p * mid, q * mid);
}

void tr(ll& x, ll& y) {
	ll g = gcd(x, y);
	x /= g;
	y /= g;
}

int main(int argc, char * argv[]) {

#ifdef LOCAL
	//gen();
	freopen("input.txt", "r", stdin);
#else
	
#endif
	
	int t;
	cin >> t;

	while (t--) {
		ll x, y, p, q;
		cin >> x >> y >> p >> q;
		tr(p, q);
		cout << go(x, y, p, q) << endl;
	}
	
	
}