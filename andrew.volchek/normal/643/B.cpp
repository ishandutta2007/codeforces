#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <tuple>
#include <complex>


using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
	return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
	return x * x;
}

template<typename T>
void chmin(T &x, T y) {
	x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
	x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
	s << "(" << x.fst << ", " << x.snd << ")";
	return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
	s << "[";
	bool was = false;
	for (auto it : x) {
		if (was) {
			s << ", ";
		}
		was = true;
		s << it;
	}
	s << "]";
	return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
	s << "{";
	bool was = false;
	for (auto it : x) {
		if (was) {
			s << ", ";
		}
		was = true;
		s << it;
	}
	s << "}";
	return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
	for (int i = 0; i < sz; i++) {
		s << x[i];
	}
	return s;
}


//-----------------------------------------------------------------------------


int main() {

#ifdef LOCAL
	freopen("a.in", "r", stdin);
	//freopen("b1.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (n == 4) {
		cout << -1 << endl;
		return 0;
	}

	if (n - 1 + 2 > k) {
		cout << -1 << endl;
		return 0;
	}

	vector<int> f;
	for (int i = 1; i <= n; i++) {
		if (i == a || i == b || i == c || i == d) {
			continue;
		}
		f.pb(i);
	}


	cout << a << " " << c;
	for (int x : f) {
		cout << " " << x;
	}

	cout << " " << d << " " << b << endl;

	cout << c << " " << a;
	for (int x : f) {
		cout << " " << x;
	}


	cout << " " << b << " " << d << endl;


	return 0;
}