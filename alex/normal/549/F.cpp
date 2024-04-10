#pragma comment(linker, "/STACK:600000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "f";

const int NMAX = 300010;
const int KMAX = 1001010;

int n, k;
int prefix[NMAX], suffix[NMAX], a[NMAX];
pii q[NMAX];
vector<int> ptable[KMAX], stable[KMAX];

void add_prefix(int val, int idx) {
	ptable[val].pb(idx);
}

void add_suffix(int val, int idx) {
	stable[val].pb(idx);
}

int calc_prefix(int l, int r, int val) {
	int ll = lower_bound(ptable[val].begin(), ptable[val].end(), l) - ptable[val].begin();
	int rr = lower_bound(ptable[val].begin(), ptable[val].end(), r + 1) - ptable[val].begin();
	return rr - ll;
}

int calc_suffix(int l, int r, int val) {
	int ll = lower_bound(stable[val].begin(), stable[val].end(), l) - stable[val].begin();
	int rr = lower_bound(stable[val].begin(), stable[val].end(), r + 1) - stable[val].begin();
	return rr - ll;
}

int64 _solve(int idx, int l, int r) {
	int64 res = 0;
	if (l == r) return 0;

	if (idx - l < r - idx) {
		res += calc_prefix(idx + 1, r, prefix[idx]);
		for (int i = l; i < idx; ++i) {
			int val = (prefix[idx] + k - (suffix[i] - suffix[idx])) % k;
			res += calc_prefix(idx + 1, r, val);
			if (val == prefix[idx]) res++;
		}
	} else {
		res += calc_suffix(l, idx - 1, suffix[idx]);
		for (int i = idx + 1; i <= r; ++i) {
			int val = (suffix[idx] + k - (prefix[i] - prefix[idx])) % k;
			res += calc_suffix(l, idx - 1, val);
			if (val == suffix[idx]) res++;
		}
	}
	return res;
}

set<int> S;

int64 solve(int idx) {
	set<int>::iterator it = S.lower_bound(idx);

	if (S.size() == 0) {
		S.insert(idx);
		return _solve(idx, 0, n - 1);
	}

	if (it == S.end()) {
		--it;
		S.insert(idx);
		return _solve(idx, *it + 1, n - 1);
	}

	if (it == S.begin()) {
		S.insert(idx);
		return _solve(idx, 0, *it - 1);
	}

	set<int>::iterator it2 = it;
	--it;
	S.insert(idx);
	return _solve(idx, *it + 1, *it2 - 1);
}

int triv() {
	int res = 0;
	forn(j, n) {
		forn(i, j) {
			int sum = 0;
			int _max = 0;
			for (int f = i; f <= j; ++f) {
				sum += a[f];
				_max = max(_max, a[f]);
			}
			sum -= _max;
			if (sum % k == 0) res++;
		}
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k;
	S.clear();
	forn(i, n)
		scanf("%d", &a[i]);

	int sum = 0;
	forn(i, n) {
		sum = (sum + a[i]) % k;
		prefix[i] = sum;
		add_prefix(sum, i);
	}
	sum = 0;
	ford(i, n) {
		sum = (sum + a[i]) % k;
		suffix[i] = sum;
		add_suffix(sum, i);
	}
	forn(i, KMAX) {
		if (ptable[i].size() > 0)
			sort(all(ptable[i]));
		if (stable[i].size() > 0)
			sort(all(stable[i]));
	}

	forn(i, n) {
		q[i] = mp(a[i], i);
	}
	sort(q, q + n);
	reverse(q, q + n);

	int64 ans = 0;
	forn(i, n) {
		ans += solve(q[i].sc);
	}
	cout << ans << endl;

	cerr << clock() << endl;
	//if (ans != triv()) {
	//	cerr << "!!!" << endl;
	//	cerr << "ANS = " << ans << endl;
	//	cerr << "TRIV = " << triv() << endl;
	//}

	return 0;
}