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

const int maxn = 5e5 + 5;
const ll inf = 1e18;


ll solve(vector<ll> a, ll k) {
	int n = a.size();
	sort(a.begin(), a.end());
	vector<ll> s(n);
	for (int i = 0; i < n; i++) {
		s[i] = a[i];
		if (i) {
			s[i] += s[i - 1];
		}
	}

	for (int i = 0; i < n; i++) {
		int j = i;
		while (j < n && a[i] == a[j]) {
			j++;
		}
		if (a[i] * j - s[j - 1] > k) {
			if (!i) {
				return a[i];
			}

			ll lo = a[i - 1], hi = a[i];
			while (hi - lo > 1) {
				ll mid = (lo + hi) >> 1;

				if (i * mid - s[i - 1] > k) {
					hi = mid;
				} else {
					lo = mid;
				}
			}

			return lo;
		}
		i = j - 1;
	}

	return inf;
}

int main() {

	srand(1234);

#ifdef LOCAL
	freopen("a.in", "r", stdin);
	//freopen("b1.out", "w", stdout);
#endif

	int n, k;
	scanf("%d %d", &n, &k);

	vector<ll> a;

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.pb(x);
	}



	ll l = solve(a, k);

	for (ll &x : a) {
		x = -x;
	}


	ll r = -solve(a, k);

	if (l < r) {
		cout << r - l << endl;
	} else {
		ll sum = 0;
		for (ll x : a) {
			sum += x;
		}
		if (sum % n == 0) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	}




	return 0;
}