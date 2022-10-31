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

	ll ax, ay, bx, by, tx, ty;
	cin >> ax >> ay >> bx >> by >> tx >> ty;

	int n;
	cin >> n;

	const ld inf = 1e28;

	ld dp[4] = {0, inf, inf, inf};

	for (int i = 0; i < n; i++) {
		ld ndp[4] = { inf, inf, inf, inf };

		ll x, y;
		cin >> x >> y;

		for (int j = 0; j < 4; j++) {
			chmin(ndp[j], dp[j] + 2.0 * sqrt(sqr(x - tx) + sqr(y - ty)));

			if (!(j & 1)) {
				chmin(ndp[j | 1], dp[j] + sqrt(sqr(ax - x) + sqr(ay - y)) + sqrt(sqr(tx - x) + sqr(ty - y)));
			}

			if (!(j & 2)) {
				chmin(ndp[j | 2], dp[j] + sqrt(sqr(bx - x) + sqr(by - y)) + sqrt(sqr(tx - x) + sqr(ty - y)));
			}
		}

		for (int j = 0; j < 4; j++) {
			dp[j] = ndp[j];
		}
	}

	cout.precision(20);
	cout << fixed << min(dp[1], min(dp[3], dp[2])) << endl;

	return 0;
}