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
const ll llinf = 3e18, mod = 1000'000'007, maxn = 1e5;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
//#define int ll

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

vector<int> q;
int l, r;
int check() {
	int n = (int)q.size();
	int ans = 0, tmp = 0, cur = 0;
	forn(i, n) {
		tmp += q[i];
		if (uax(ans, tmp)) {
			l = cur;
			r = i;
		}
		if (q[i] == 1) tmp = 1, cur = i;
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, l1, r1, mn;
	cin >> n;
	vector<int> a(n), out;
	forn(i, n) {
		cin >> a[i];
	}
	sort(all(a));
	int ans = 0;
	forn(i, n) {
		if (i > 0 && a[i] > a[i - 1] + 1) {
			if (uax(ans, check())) {
				l1 = l; r1 = r; mn = a[i - 1] - (int)q.size() + 1;
				out.resize(q.size());
				copy(all(q), out.begin());
			}
			q.clear();
		}
		if (i > 0 && a[i] == a[i - 1]) q.back()++;
		else q.push_back(1);
	}
	if (uax(ans, check())) {
		l1 = l; r1 = r; mn = a[n - 1] - (int)q.size() + 1;
		out.resize(q.size());
		copy(all(q), out.begin());
	}
	cout << ans << el;
	for (int i = l1; i < r1; ++i) cout << mn + i << ' ';
	forn(i, out[r1]) cout << mn + r1 << ' ';
	for (int i = r1 - 1; i >= l1; --i)
		forn(k, out[i] - 1) cout << mn + i << ' ';
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}