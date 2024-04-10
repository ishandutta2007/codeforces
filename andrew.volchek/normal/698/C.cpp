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


const int maxn = 1 << 20;

ld a[maxn];


void rec(int l, int r) {
	if (l == r) {
		return;
	}
	int c = (l + r) >> 1;
	for (int i = l; i <= c; i++) {
		a[c + i - l + 1] += a[i];
	}
	rec(l, c);
	rec(c + 1, r);
}

int main() {
	srand(time(NULL));

	retry:
#ifdef LOCAL
	//gen();
	freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#else
	//freopen("lock.in", "r", stdin);
    //freopen("lock.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<ld> p(n);
	ld eps = 1e-9;
	bool one = false;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		one |= abs(p[i] - 1) < eps;
	}
	if (one) {
		cout.precision(10);
		for (int j = 0; j < n; j++) {
			if (j) {
				cout << " ";
			}
			cout << fixed << p[j];
		}
		cout << endl;
		return 0;
	}
	vector<ld> ans(n, 0);
	for (int i = 1; i < (1 << n); i++) {
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			cnt += bool(i & (1 << j));
			a[i] += p[j] * bool(i & (1 << j));
		}

		a[i] = 1.0 / (1.0 - a[i]) * a[i];
		if (cnt & 1) {
			a[i] = -a[i];
		}
	}


	rec(0, (1 << n) - 1);

	ans = p;


	for (int i = 1; i < (1 << n); i++) {
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			cnt += bool(i & (1 << j));
		}

		if (cnt > k - 1) {
			continue;
		}

		if (cnt & 1) {
			a[i] = -a[i];
		}

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				continue;
			}
			if (abs(p[j]) < eps) {
				continue;
			}
			ans[j] += p[j] * a[i];
		}
	}

	cout.precision(10);
	for (int j = 0; j < n; j++) {
		if (j) {
			cout << " ";
		}
		cout << fixed << ans[j];
	}
	cout << endl;


	return 0;
}