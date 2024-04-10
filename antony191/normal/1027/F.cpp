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
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 998244353, md = 998244352;
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

const int maxn = 3e6;
vector<int> g[maxn], p, cnt, sz;
vector<char> used;
void init(int n, int t) {
	p.resize(n + t); cnt.resize(n + t); sz.assign(n + t, 1);
	forn(i, n + t) {
		p[i] = i;
		cnt[i] = i < n ? -1 : 1;
	}
}
int getp(int a) {
	return a == p[a] ? a : p[a] = getp(p[a]);
}
int unite(int a, int b) {
	a = getp(a); b = getp(b);
	if (a == b) return 0;
	int tmp = 0;
	if (cnt[a] < 0) tmp--;
	if (cnt[b] < 0) tmp--;
	if (sz[a] < sz[b]) swap(a, b);
	p[b] = a;
	cnt[a] += cnt[b];
	sz[a] += sz[b];
	if (cnt[a] < 0) tmp++;
	return tmp;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	vector<int> q;
	forn(i, n) {
		cin >> a[i].x >> a[i].y;
		q.push_back(a[i].x); q.push_back(a[i].y);
	}
	sort(all(q));
	q.resize(distance(q.begin(), unique(all(q))));
	forn(i, n) {
		a[i].x = lower_bound(all(q), a[i].x) - q.begin();
		a[i].y = lower_bound(all(q), a[i].y) - q.begin();
		g[i].push_back(a[i].x + n); g[i].push_back(a[i].y + n);
		g[a[i].x + n].push_back(i); g[a[i].y + n].push_back(i);
	}
	int i, t = (int)q.size(), cnt = n;
	init(n, t);
	for (i = 0; i < t; ++i) {
		for (auto to : g[i + n])
			cnt += unite(i + n, to);
		if (cnt == 0) break;
	}
	cout << (i < t ? q[i] : -1) << el;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}