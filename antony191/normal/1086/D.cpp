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
const ll llinf = 1e18, mod = 1000'000'007;
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

int n;
vector<int> f[3];
void upd(int p, int x, int d) {
	for (; x < n; x = x | (x + 1))
		f[p][x] += d;
}
int sum(int p, int r) {
	int ans = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		ans += f[p][r];
	return ans;
}
int sum(int p, int l, int r) {
	return sum(p, r) - (l == 0 ? 0 : sum(p, l - 1));
}
int ch(char c) {
	return (c == 'P' ? 0 : (c == 'R' ? 1 : 2));
}
int fir[3], las[3], ssum[3];
void ss() {
	ssum[0] = sum(0, 0, n - 1);
	ssum[1] = sum(1, 0, n - 1);
	ssum[2] = sum(2, 0, n - 1);
}
void al(int p) {
	int l = -1, r = n - 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (sum(p, 0, m) > 0) r = m;
		else l = m;
	}
	fir[p] = r;
	l = 0, r = n;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (sum(p, m, n - 1) > 0) l = m;
		else r = m;
	}
	las[p] = l;
}
int ans(int p) {
	int p1 = (p == 2 ? 0 : p + 1);
	int p2 = (p1 == 2 ? 0 : p1 + 1);
	if (ssum[p1] == 0)
		return ssum[p2] == 0 ? ssum[p] : 0;
	int an = sum(p, fir[p1], las[p1]);
	an += sum(p, min(fir[p1], fir[p2]));
	an += sum(p, max(las[p1], las[p2]), n - 1);
	return an;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> n >> q;
	vector<char> a(n);
	f[0].resize(n); f[1].resize(n); f[2].resize(n);
	forn(i, n) {
		cin >> a[i];
		upd(ch(a[i]), i, 1);
	}
	ss();
	al(0); al(1); al(2);
	cout << ans(0) + ans(1) + ans(2) << el;
	forn(i, q) {
		int x;
		char c;
		cin >> x >> c;
		x--;
		upd(ch(a[x]), x, -1);
		upd(ch(c), x, 1);
		a[x] = c;
		ss();
		al(0); al(1); al(2);
		cout << ans(0) + ans(1) + ans(2) << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}