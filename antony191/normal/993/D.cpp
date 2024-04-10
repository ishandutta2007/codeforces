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

#define int ll
const int N = 51;
int dp[51][5001][101];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	map<int, vector<int>> q;
	vector<int> t(n);
	forn(i, n) cin >> t[i];
	forn(i, n) {
		int c;
		cin >> c;
		q[t[i]].push_back(c);
	}
	for (auto i = q.begin(); i != q.end(); ++i) {
		sort(all(i->y));
		reverse(all(i->y));
	}
	forn(i, 51) forn(j, 5001) forn(k, 101) dp[i][j][k] = llinf;
	dp[0][0][0] = 0;
	int cnt = 0;
	for (auto i = q.rbegin(); i != q.rend(); ++i) {
		auto a = i->y;
		int w = i->x, m = (int)a.size();
		forn(j, 5001)
			forn(k, 51) {
			int t = 0;
			forn(l, m + 1) {
				if (k + m - l - l >= m - l && t <= j)
					uin(dp[cnt + 1][j][k], dp[cnt][j - t][k + m - l - l] + w * l);
				if (l < m) t += a[l];
			}
		}
		cnt++;
	}
	ld ans = (ld)llinf;
	firn(j, 100 * n + 1)
		forn(k, n + 1) {
		uin(ans, (ld)dp[cnt][j][k] / (ld)j);
	}
	ans *= 1000.0;
	int out = ceil(ans);
	cout << out;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}