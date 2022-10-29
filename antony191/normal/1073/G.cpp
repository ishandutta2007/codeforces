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

int n, hmax = 0;
vector<int> p1[20], c1[20], l, t;

void build(int v, int tl, int tr) {
	if (tl == tr)
		t[v] = l[tl];
	else {
		int m = (tl + tr) >> 1;
		build(v + v, tl, m);
		build(v + v + 1, m + 1, tr);
		t[v] = min(t[v + v], t[v + v + 1]);
	}
}
int get(int v, int tl, int tr, int l, int r) {
	if (tl == l && tr == r) {
		return t[v];
	}
	int m = (tl + tr) >> 1;
	int tmp = inf;
	if (l <= m) uin(tmp, get(v + v, tl, m, l, min(m, r)));
	if (r >= m + 1) uin(tmp, get(v + v + 1, m + 1, tr, max(l, m + 1), r));
	return tmp;
}
int lcp(int a, int b) {
	int h = hmax;
	int ans = 0;
	while (h + 1) {
		if (c1[h][a] == c1[h][b]) ans += (1 << h), a = (a + (1 << h)) % n, b = (b + (1 << h)) % n;
		h--;
	}
	return ans;
}
ll solve(vector<int> & a) {
	if (a.size() <= 1) return 0;
	vector<int> k((int)a.size() - 1);
	firn(i, a.size()) {
		if (a[i - 1] == a[i])
			k[i - 1] = n - 1 - p1[hmax + 1][a[i - 1]];
		else
			k[i - 1] = get(1, 0, n - 2, a[i - 1], a[i] - 1);
	}
	int m = (int)k.size();
	vector<int> leftmin(m, -1), stack;
	stack.push_back(0);
	firn(i, m) {
		while (!stack.empty() && k[i] < k[stack.back()]) stack.pop_back();
		if (!stack.empty()) leftmin[i] = stack.back();
		stack.push_back(i);
	}
	vector<int> rightmin(m, m);
	stack.clear();
	stack.push_back(m - 1);
	for (int i = m - 2; i >= 0; --i) {
		while (!stack.empty() && k[i] <= k[stack.back()]) stack.pop_back();
		if (!stack.empty()) rightmin[i] = stack.back();
		stack.push_back(i);
	}
	ll ans = 0;
	forn(i, m) {
		int l = i - leftmin[i] - 1, r = rightmin[i] - i - 1;
		ll tmp = 0ll;
		tmp += (r + l + 1) * 1ll * (r + l + 2) / 2ll;
		tmp -= l * 1ll * (l + 1) / 2ll;
		tmp -= r * 1ll * (r + 1) / 2ll;
		ans += tmp * 1ll * k[i];
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> n >> q;
	string s;
	cin >> s;
	n++; s += '#';
	vector<int> p(n), c(n), cnt(256);
	forn(i, n) cnt[s[i]]++;
	firn(i, 256) cnt[i] += cnt[i - 1];
	forn(i, n) p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int cls = 1;
	firn(i, n) {
		if (s[p[i]] != s[p[i - 1]]) cls++;
		c[p[i]] = cls - 1;
	}
	forn(i, 20) p1[i].resize(n), c1[i].resize(n);
	copy(all(p), p1[0].begin()); copy(all(c), c1[0].begin());
	vector<int> pn(n), cn(n);
	for (int h = 0; (1 << h) < n; ++h) {
		uax(hmax, h);
		forn(i, n) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0) pn[i] += n;
		}
		cnt.assign(cls, 0);
		forn(i, n) cnt[c[pn[i]]]++;
		firn(i, cls) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i + 1; --i)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		cls = 1;
		firn(i, n) {
			int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i - 1] + (1 << h)) % n;
			if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) cls++;
			cn[p[i]] = cls - 1;
		}
		copy(all(cn), c.begin());
		copy(all(p), p1[h + 1].begin());
		copy(all(c), c1[h + 1].begin());
	}
	vector<int> pos(n);
	forn(i, n) pos[p[i]] = i;
	l.resize(n - 1);
	firn(i, n) {
		l[i - 1] = lcp(p[i - 1], p[i]);
		uin(l[i - 1], min(n - p[i], n - p[i - 1]));
	}
	t.resize(4 * n);
	build(1, 0, n - 2);
	while (q--) {
		int k, l;
		cin >> k >> l;
		vector<int> a(k), b(l);
		forn(i, k) cin >> a[i];
		forn(i, l) cin >> b[i];
		forn(i, k) {
			a[i] = pos[a[i] - 1];
		}
		sort(all(a));
		forn(i, l) {
			b[i] = pos[b[i] - 1];
		}
		sort(all(b));
		ll ans = 0ll;
		ans -= solve(a);
		ans -= solve(b);
		vector<int> e;
		e.resize(a.size() + b.size());
		merge(all(a), all(b), e.begin());
		ans += solve(e);
		cout << ans << '\n';
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}