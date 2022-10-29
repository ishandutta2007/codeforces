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

const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

int n;
vector<ll> a, f;

void upd(int i, ll add) {
	for (; i < n; i = i | (i + 1))
		f[i] += add;
}
ll sum(int r) {
	if (r < 0) return 0ll;
	ll ans = 0ll;
	for (; r + 1; r = (r & (r + 1)) - 1)
		ans += f[r];
	return ans;
}
ll sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

vector<int> t1;

void upd1(int i, int add) {
	for (; i < n; i = i | (i + 1))
		t1[i] += add;
}
int sum1(int r) {
	int ans = 0;
	if (r < 0) return 0;
	for (; r + 1; r = (r & (r + 1)) - 1)
		ans += t1[r];
	return ans;
}
int sum1(int l, int r) {
	return sum1(r) - sum1(l - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	ll t;
	cin >> t;
	a.resize(n);
	forn(i, n) cin >> a[i];
	f.resize(n);
	t1.resize(n);
	forn(i, n) upd(i, a[i]), upd1(i, 1);
	int cur = 0, cnt = n;
	ll ans = 0ll, s = sum(0, n - 1);
	while (cnt) {
		ll tmp = t / s;
		ans += tmp * 1ll * cnt;
		t -= tmp * s;
		int l = cur - 1, r = n + cur - 1;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			ll tmp = 0;
			if (m < n) tmp = sum(cur, m);
			else tmp = sum(cur, n - 1) + sum(0, m - n);
			if (tmp <= t)
				l = m;
			else
				r = m;
		}
		if (r > cur) {
			if (r - 1 < n)
				t -= sum(cur, r - 1), ans += sum1(cur, r - 1) * 1ll;
			else
				t -= sum(cur, n - 1) + sum(0, r - 1 - n), ans += sum1(cur, n - 1) * 1ll + sum1(0, r - 1 - n);
		}
		s -= a[r % n];
		upd(r % n, -a[r % n]);
		upd1(r % n, -1);
		cur = (r + 1) % n;
		cnt--;
	}
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}