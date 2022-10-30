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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	forn(i, n) {
		char tmp;
		cin >> tmp;
		switch (tmp) {
		case 'L':
			a[i] = 0;
			break;
		case 'R':
			a[i] = 1;
			break;
		case 'D':
			a[i] = 2;
			break;
		case 'U':
			a[i] = 3;
			break;
		}
	}
	int x, y;
	cin >> x >> y;
	if (((x + y) & 1) != (n & 1) || abs(x) + abs(y) > n) return cout << -1, 0;
	int ans = inf;
	vector<pair<int, int>> suf(n + 1);
	suf[n] = { 0, 0 };
	for (int i = n - 1; i + 1; --i) {
		suf[i] = suf[i + 1];
		switch (a[i]) {
		case 0:
			suf[i].first--;
			break;
		case 1:
			suf[i].first++;
			break;
		case 2:
			suf[i].second--;
			break;
		case 3:
			suf[i].second++;
			break;
		}
	}
	auto k = pair<int, int>{ x, y };
	if (suf[0] == pair<int, int>{x, y})
		cout << 0;
	else {
		forn(i, n) {
			int l = i, r = n;
			k = { x, y };
			k.first -= suf[0].first - suf[i].first;
			k.second -= suf[0].second - suf[i].second;
			if (n - i < abs(k.first) + abs(k.second)) break;
			while (r - l > 1) {
				int m = (l + r) >> 1;
				k = { x, y };
				k.first -= suf[0].first - (suf[i].first - suf[m].first);
				k.second -= suf[0].second - (suf[i].second - suf[m].second);
				if (m - i >= abs(k.first) + abs(k.second))
					r = m;
				else
					l = m;
			}
			uin(ans, r - i);
		}
		cout << ans;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}