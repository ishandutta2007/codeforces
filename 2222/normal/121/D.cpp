#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n, m;
ll lim, w;
vector<ll> lucky;
vector<ll> L, R;

inline ll add(ll x, ll y) {
	return min(x + y, 1000000000000000001);
}

inline ll mul(ll x, int k) {
	ll y = 0;
	for (; k; k /= 2) {
		if (k & 1) y = add(y, x);
		x = add(x, x);
	}
	return y;
}

void go(unsigned long long x) {
	if (x > 0 && x <= 2000000000000000000)
		lucky.pb(x);
	if (x <= -1ull / 10) {
		go(x * 10 + 4);
		go(x * 10 + 7);
	}
}

ll x[100500], y[100500];

bool check(int k) {
	int i = 0, j = k - 1;
	for (; j < m; ++i, ++j) {
		if (lucky[j] - lucky[i] <= w && L[i] + R[j] <= lim) 
			return true;
	}
	return false;
}

int main() {
	go(0);
	sort(all(lucky));
	m = sz(lucky);
	L.resize(m);
	R.resize(m);
	cin >> n >> lim;
	w = -1ull/2;
	REP (i, n) {
		cin >> x[i];
		cin >> y[i];
		w = min(w, y[i] - x[i]);
	}
	sort(x, x + n);
	sort(y, y + n);
	int i = 0, j = 0, k = 0;
	ll s = 0;
	for (; i < m; ++i) {
		if (k) s = add(s, mul(lucky[i] - lucky[i - 1], k));
		for (; j < n && y[j] < lucky[i]; ++j, ++k) {
			s = add(s, lucky[i] - y[j]);
		}
		R[i] = s;
	}
	i = m - 1;
	j = n - 1;
	k = 0;
	s = 0;
	for (; i >= 0; --i) {
		if (k) s = add(s, mul(lucky[i + 1] - lucky[i], k));
		for (; j >= 0 && x[j] > lucky[i]; --j, ++k) {
			s = add(s, x[j] - lucky[i]);
		}
		L[i] = s;
	}
	int l = 1, r = m;
	for (; l <= r; ) {
		int k = (l + r) / 2;
		check(k) ? l = k + 1 : r = k - 1;
	}
	cout << r << endl;
	return 0;
}