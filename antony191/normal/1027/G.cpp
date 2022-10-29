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
#pragma GCC optimize("vpt")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1000'000'000'000'22;
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

#define int ll
vector<pair<int, int>> fact(int t) {
	vector<pair<int, int>> p;
	for (int i = 2; i * i <= t; ++i) {
		if (t % i) continue;
		p.emplace_back(i, 0);
		while (!(t % i)) {
			t /= i;
			p.back().y++;
		}
	}
	if (t > 1) p.emplace_back(t, 1);
	return p;
}
int m, k = 10000;
int mult(int a, int b) {
	if (!b) return 0;
	return (mult(a, b / k) * k + a * (b % k)) % m;
}
int fast(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) {
			res = mult(res, a);
		}
		a = mult(a, a);
		n >>= 1;
	}
	return res;
}
int gcd(int a, int b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	cin >> m >> x;
	auto p = fact(m);
	int phi = m;
	forn(i, p.size()) {
		phi = (phi / p[i].x) * (p[i].x - 1);
	}
	//auto q = fact(phi);
	vector<int> del, md;
	for (int i = 1; i * i <= phi; ++i) {
		if (phi % i) continue;
		del.push_back(i);
		if (i * i != phi) del.push_back(phi / i);
	}
	for (int i = 1; i * i <= m; ++i) {
		if (m % i) continue;
		md.push_back(i);
		if (i * i != m) md.push_back(m / i);
	}
	sort(all(md));
	sort(all(del));
	vector<int> p1(p.size(), 1), ans(md.size(), phi);
	forn(i, p.size()) {
		forn(j, p[i].y) p1[i] *= p[i].x;
	}
	forn(i, del.size()) {
		auto t = fast(x, del[i]);
		if (t <= 0) t += m;
		int y = gcd(m, t - 1);
		uin(ans[lower_bound(all(md), y) - md.begin()], del[i]);
		if (y == m) break;
	}
	int as = 0;
	for (int i = (int)md.size() - 1; i + 1; --i) {
		int phi1 = md[i];
		forn(j, p.size()) {
			if (md[i] % p1[j]) {
				uin(ans[i], ans[lower_bound(all(md), md[i] * p[j].x) - md.begin()]);
			}
			if (!(md[i] % p[j].x)) phi1 = (phi1 / p[j].x) * (p[j].x - 1);
		}
		as += phi1 / ans[i];
	}
	cout << as;
	cin >> as;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}