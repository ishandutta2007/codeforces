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
const ll llinf = 1e18, mod = 1000'003;
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

const int maxn = 100228;
ll dp[maxn][201];
vector<pair<int, int>> l[maxn], r[maxn];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> s(k), t(k), d(k);
	vector<ll> w(k);
	forn(i, k) {
		cin >> s[i] >> t[i] >> d[i] >> w[i];
		s[i]--; t[i]--; d[i]--;
		l[s[i]].emplace_back(w[i], d[i]);
		r[t[i]].emplace_back(w[i], d[i]);
	}
	vector<pair<int, int>> a(n);
	multiset<pair<int, int>> q;
	forn(i, n) {
		for (auto to : l[i]) q.insert(to);
		a[i] = (q.empty() ? pair<int, int>{0, i} : *q.rbegin());
		for (auto to : r[i]) q.erase(q.find(to));
	}
	for (int i = n - 1; i >= 0; --i) {
		dp[i][0] = a[i].x * 1ll + dp[a[i].y + 1][0];
		firn(j, m + 1) {
			dp[i][j] = min(a[i].x * 1ll + dp[a[i].y + 1][j], dp[i + 1][j - 1]);
		}
	}
	cout << dp[0][m];
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}