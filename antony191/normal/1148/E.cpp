#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

struct aa {
	int i, j, d;
};
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	vector<pair<int, int>> a1(n);
	forn(i, n) cin >> a[i];
	forn(i, n) cin >> b[i];
	forn(i, n) {
		a1[i] = { a[i], i };
	}
	ll sum = 0;
	forn(i, n) sum += 1ll * (a[i] - b[i]);
	if (sum != 0) return cout << "NO", 0;
	sort(all(a)); sort(all(b)); sort(all(a1));
	vector<int> pl, mn;
	forn(i, n) {
		if (a[i] < b[i]) pl.push_back(i);
		else mn.push_back(i);
		c[i] = abs(a[i] - b[i]);
	}
	bool ok = 1;
	vector<aa> ans;
	int i = 0, j = 0;
	while (i < (int)pl.size() && j < (int)mn.size()) {
		while (i < (int)pl.size() && c[pl[i]] == 0) i++;
		while (j < (int)mn.size() && c[mn[j]] == 0) j++;
		if (i == (int)pl.size() || j == (int)mn.size()) break;
		if (pl[i] > mn[j]) {
			ok = 0;
			break;
		}
		ans.push_back({ pl[i], mn[j], min(c[pl[i]], c[mn[j]]) });
		int k = min(c[pl[i]], c[mn[j]]);
		c[pl[i]] -= k;
		a[pl[i]] += k;
		c[mn[j]] -= k;
		a[mn[j]] -= k;
	}
	sort(all(a));
	if (a != b) ok = 0;
	if (!ok) cout << "NO";
	else {
		cout << "YES" << el;
		cout << (int)ans.size() << el;
		for (auto i : ans)
			cout << a1[i.i].y + 1 << ' ' << a1[i.j].y + 1 << ' ' << i.d << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}