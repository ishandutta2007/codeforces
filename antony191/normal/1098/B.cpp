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
const int inf = 2e9;
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

char symb(int v) {
	return (v == 0 ? 'A' : (v == 1 ? 'G' : (v == 2 ? 'C' : 'T')));
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	forn(i, n)
		forn(j, m) {
		char c;
		cin >> c;
		if (c == 'A') a[i][j] = 0;
		else if (c == 'G') a[i][j] = 1;
		else if (c == 'C') a[i][j] = 2;
		else a[i][j] = 3;
	}
	vector<int> b[2][4];
	forn(i, 2) forn(j, 4) b[i][j].resize(m);
	forn(i, n)
		forn(j, m) {
		b[i & 1][a[i][j]][j]++;
	}
	vector<int> dp[16];
	forn(i, 16) dp[i].resize(m);
	forn(i, 16) {
		int x = i & 3, y = i >> 2;
		if (x == y) continue;
		int cnt = 0;
		cnt += b[0][x][m - 1] + b[1][y][m - 1];
		dp[i][m - 1] = cnt;
	}
	for (int i = m - 2; i >= 0; --i)
		forn(j, 16) {
		int x = j & 3, y = j >> 2;
		if (x == y) continue;
		dp[j][i] = b[0][x][i] + b[1][y][i];
		vector<int> tmp;
		forn(k, 4) if (k != x && k != y) tmp.push_back(k);
		dp[j][i] += max(dp[tmp[0] + tmp[1] * 4][i + 1], dp[tmp[1] + tmp[0] * 4][i + 1]);
	}
	int ans = 0, ians[2] = { -1, -1 };
	forn(i, 16) {
		if ((i & 3) == (i >> 2)) continue;
		if (uax(ans, dp[i][0]))
			ians[0] = i & 3, ians[1] = i >> 2;
	}
	int imax[2] = { -1, -1 }, mx = 0;
	forn(i, 4)
		for (int j = i + 1; j < 4; ++j) {
			int tmp = 0;
			vector<int> l;
			forn(k, 4) if (k != i && k != j) l.push_back(k);
			forn(k, n) {
				int t[2] = { 0, 0 };
				forn(r, m) {
					if (k & 1) {
						if (a[k][r] == l[0])
							t[r & 1]++;
						if (a[k][r] == l[1])
							t[!(r & 1)]++;
					}
					else {
						if (a[k][r] == i)
							t[r & 1]++;
						if (a[k][r] == j)
							t[!(r & 1)]++;
					}
				}
				tmp += max(t[0], t[1]);
			}
			if (uax(mx, tmp))
				imax[0] = i, imax[1] = j;
		}
	if (ans > mx) {
		vector<int> ans1(m), ans2(m);
		ans1[0] = ians[0]; ans2[0] = ians[1];
		firn(i, m) {
			vector<int> tmp;
			forn(k, 4) if (k != ians[0] && k != ians[1]) tmp.push_back(k);
			if (dp[tmp[0] + tmp[1] * 4][i] > dp[tmp[1] + tmp[0] * 4][i])
				ians[0] = tmp[0], ians[1] = tmp[1];
			else ians[0] = tmp[1], ians[1] = tmp[0];
			ans1[i] = ians[0];
			ans2[i] = ians[1];
		}
		forn(i, n)
			if (i & 1) {
				forn(j, m)
					cout << symb(ans2[j]);
				cout << el;
			}
			else {
				forn(j, m)
					cout << symb(ans1[j]);
				cout << el;
			}
	}
	else {
		vector<int> l;
		forn(i, 4) if (i != imax[0] && i != imax[1]) l.push_back(i);
		forn(i, n) {
			int t[2] = { 0, 0 };
			forn(j, m) {
				if (i & 1) {
					if (a[i][j] == l[0])
						t[j & 1]++;
					if (a[i][j] == l[1])
						t[!(j & 1)]++;
				}
				else {
					if (a[i][j] == imax[0])
						t[j & 1]++;
					if (a[i][j] == imax[1])
						t[!(j & 1)]++;
				}
			}
			if (t[0] >= t[1]) {
				forn(j, m)
					if (i & 1) cout << symb(l[j & 1]);
					else cout << symb(imax[j & 1]);
			}
			else {
				forn(j, m)
					if (i & 1) cout << symb(l[!(j & 1)]);
					else cout << symb(imax[!(j & 1)]);
			}
			cout << el;
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}