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

bool a[200][200];

pair<vector<int>, vector<int>> solve(int n, int m) {
	vector<int> ans(m), row(n);
	forn(i, m) ans[i] = a[0][i];
	int ok = 1, cnt[2], aft = 0;
	forn(i, n) {
		cnt[0] = cnt[1] = 0;
		forn(j, m) cnt[a[i][j] ^ ans[j]]++;
		if (cnt[0] == 0 || cnt[1] == 0) {
			if ((cnt[0] == 0 && !aft) || (cnt[1] == 0 && aft))
				row[i] = 1;
			continue;
		}
		if (aft) {
			ok = 0;
			break;
		}
		aft = 1;
		if ((a[i][0] ^ ans[0]) == 1) {
			row[i] = 1;
		}
		bool tmp = 0;
		forn(j, m) {
			if ((a[i][j] ^ row[i] ^ ans[j]) == 1) tmp = 1;
			if (tmp && (a[i][j] ^ row[i] ^ ans[j]) == 0) {
				ok = 0;
				break;
			}
		}
		if (!ok) break;
	}
	if (!ok) return { vector<int>(0), vector<int>(0) };
	return { row, ans };
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	forn(i, n) forn(j, m) cin >> a[i][j];
	if (n == 1) {
		cout << "YES" << el << 0 << el;
		forn(i, m) cout << a[0][i];
		cout << el;
		return 0;
	}
	auto k = solve(n, m);
	if (!k.x.empty()) {
		cout << "YES" << el;
		for (auto i : k.x) cout << i;
		cout << el;
		for (auto i : k.y) cout << i;
		cout << el;
	}
	else {
		forn(i, n)
			forn(j, (m + 1) / 2) {
			if (i >= (n / 2) && j + j + 1 == m) continue;
			swap(a[i][j], a[n - i - 1][m - j - 1]);
		}
		forn(i, n) forn(j, m) a[i][j] = !a[i][j];
		auto k = solve(n, m);
		if (!k.x.empty()) {
			cout << "YES" << el;
			reverse(all(k.x)); reverse(all(k.y));
			for (auto i : k.x) cout << i;
			cout << el;
			for (auto i : k.y) cout << i;
			cout << el;
		}
		else cout << "NO" << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}