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

vector<int> p0, p1, sz0, sz1;
void init(int n) {
	p0.resize(n); p1.resize(n); sz0.assign(n, 1); sz1.assign(n, 1);
	forn(i, n) p0[i] = p1[i] = i;
}
int get0(int a) {
	return a == p0[a] ? a : p0[a] = get0(p0[a]);
}
int get1(int a) {
	return a == p1[a] ? a : p1[a] = get1(p1[a]);
}
void unite0(int a, int b) {
	a = get0(a); b = get0(b);
	if (sz0[a] < sz0[b]) swap(a, b);
	p0[b] = a;
	sz0[a] += sz0[b];
}
void unite1(int a, int b) {
	a = get1(a); b = get1(b);
	if (sz1[a] < sz1[b]) swap(a, b);
	p1[b] = a;
	sz1[a] += sz1[b];
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	init(n);
	forn(i, n - 1) {
		int v, u, c;
		cin >> v >> u >> c;
		v--; u--;
		if (c) unite1(v, u);
		else unite0(v, u);
	}
	ll ans = 0;
	forn(i, n) {
		ans += sz0[get0(i)] * 1ll * sz1[get1(i)];
	}
	cout << ans - n;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}