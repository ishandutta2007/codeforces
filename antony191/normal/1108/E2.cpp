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
vector<int> a, la[maxn], ra[maxn];
struct node {
	int min, add, l, r;
	node() { add = 0; }
};
struct Segment_Tree {
	vector<node> t;
	void build(int l, int r, int v = 1) {
		t[v].l = l;
		t[v].r = r;
		if (l + 1 == r) {
			t[v].min = a[l];
		}
		else {
			int m = (l + r) >> 1;
			build(l, m, v + v);
			build(m, r, v + v + 1);
			t[v].min = min(t[v + v].min, t[v + v + 1].min);
		}
	}
	Segment_Tree() {}
	Segment_Tree(int n) {
		t.resize(4 * n);
		build(0, n);
	}
	void push(int v) {
		t[v + v].add += t[v].add;
		t[v + v + 1].add += t[v].add;
		t[v].add = 0;
	}
	void update(int l, int r, int add, int v = 1) {
		if (l >= r) return;
		if (t[v].l == l && t[v].r == r) {
			t[v].add += add;
		}
		else {
			int m = (t[v].l + t[v].r) >> 1;
			push(v);
			update(l, min(m, r), add, v + v);
			update(max(l, m), r, add, v + v + 1);
			t[v].min = min(t[v + v].min + t[v + v].add, t[v + v + 1].min + t[v + v + 1].add);
		}
	}
	int get() {
		return t[1].min + t[1].add;
	}
};
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	a.resize(n);
	forn(i, n) {
		cin >> a[i];
	}
	Segment_Tree T(n);
	vector<pair<int, int>> edge(m);
	forn(i, m) {
		cin >> edge[i].x >> edge[i].y;
		edge[i].x--; edge[i].y--;
		T.update(edge[i].x, edge[i].y + 1, -1);
		la[edge[i].x].push_back(i);
		ra[edge[i].y].push_back(i);
	}
	int ians = 0, ans = -1;
	forn(i, n) {
		if (i > 0) {
			for (auto to : ra[i - 1]) T.update(edge[to].x, edge[to].y + 1, -1);
		}
		for (auto to : la[i]) T.update(edge[to].x, edge[to].y + 1, 1);
		if (a[i] - T.get() > ans) {
			ians = i;
			ans = a[i] - T.get();
		}
	}
	vector<int> out;
	cout << ans << el;
	forn(i, m) if (edge[i].x > ians || edge[i].y < ians) out.push_back(i + 1);
	cout << (int)out.size() << el;
	for (auto to : out) cout << to << ' ';
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}