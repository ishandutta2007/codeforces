#pragma comment(linker, "/STACK:600000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
#define sz(s) int((s).size())

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "e";

const int NMAX = 200010;

int n, a[NMAX], d[NMAX][6], ans[NMAX], prev[NMAX][6];
vector<pii> q;

vector<pii> get_opt(int idx1, int col1, int sh1, int idx2, int col2, int sh2, bool& answer) {
	vector<pii> res;
	answer = 0;
	//if (col1 > col2 || (col1 == col2 && sh1 >= sh2)) return res;
	if (col1 == col2) {
		if (sh2 - sh1 == idx2 - idx1) {
			forn(i, sh2 - sh1 - 1)
				res.pb(mp(idx1 + i + 1, col1));
			answer = 1;
		}
		return res;
	}

	vector<pii> RES;
	forn(i, sh2 - 1)
		RES.pb(mp(idx2 - i - 1, col2));
	idx2 -= sh2, col2--;
	for (int i = max(0, 2 - sh1); i < 6 - sh1; ++i) {
		res = RES;
		forn(j, i)
			res.pb(mp(idx1 + j + 1, col1));
		int newidx1 = idx1 + i + 1;
		int newcol1 = col1 + 1;

		if (col2 == col1 - 1) {
			if (idx2 == newidx1 - 1) {
				answer = 1;
				return res;
			}
			continue;
		}
		int delta_idx = idx2 - newidx1 + 1;
		int delta_col = col2 - newcol1 + 1;
		if (2 * delta_col <= delta_idx && delta_idx <= 5 * delta_col) {
			int sz, num;
			if (delta_col == 0) sz = 0, num = 0;
			else sz = delta_idx / delta_col, num = delta_col - delta_idx % delta_col;
			forn(j, num) {
				forn(f, sz)
					res.pb(mp(newidx1++, newcol1));
				newcol1++;
			}
			forn(j, delta_col - num) {
				forn(f, sz + 1)
					res.pb(mp(newidx1++, newcol1));
				newcol1++;
			}
			answer = 1;
			return res;
		}
	}
	res.clear();
	return res;
}

int may(int idx1, int col1, int sh1, int idx2, int col2, int sh2) {
	bool answer = 0;
	vector<pii> ept = get_opt(idx1, col1, sh1, idx2, col2, sh2, answer);
	return answer;
}

void rec(int x, int y) {
	ans[q[x].fs] = q[x].sc;
	//if (q[x].sc == 1925 && x > 0 && q[x - 1].sc == 1925 && y == prev[x][y]) exit(1);
	if (x == 0) return;
	rec(x - 1, prev[x][y]);
	bool unused = 0;
	vector<pii> ept = get_opt(q[x - 1].fs, q[x - 1].sc, prev[x][y], q[x].fs, q[x].sc, y, unused);

	forn(i, ept.size())
		ans[ept[i].fs] = ept[i].sc;
}

int main() {
//	freopen((name + ".in").data(), "r", stdin);
//	freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	q.pb(mp(0, 1));
	forn(i, n) {
		scanf("%d", &a[i]);
		if (i == 0 && a[i] != 0) {
			if (a[i] != 1) {
				cout << -1 << endl;
				return 0;
			}
		}
		else if (a[i] != 0) q.pb(mp(i, a[i]));
	}
	seta(d, 0);
	d[0][1] = 1;
	forn(i, q.size() - 1)
		forn(j, 6)
			if (j && d[i][j]) 
				forn(f, 6) {
					if (f && may(q[i].fs, q[i].sc, j, q[i + 1].fs, q[i + 1].sc, f)) {
						d[i + 1][f] = 1;
						prev[i + 1][f] = j;
					}
				}

	ford(j, 6)
		if (d[q.size() - 1][j] && (j >= 2 || q[q.size() - 1].fs != n - 1) && (j <= 4 || q[q.size() - 1].fs != n - 2)) {
			rec(q.size() - 1, j);
			int now = q[q.size() - 1].fs + 1;
			if (j == 1)
				ans[now++] = q[q.size() - 1].sc;
			while (now < n) {
				if (now == n - 1) {
					ans[now] = ans[now - 1];
					now++;
				}
				else {
					ans[now] = ans[now - 1] + 1;
					ans[now + 1] = ans[now - 1] + 1;
					now += 2;
				}
			}
			cout << ans[n - 1] << endl;
			forn(i, n) {
				if (i) printf(" ");
				printf("%d", ans[i]);
			}
			cout << endl;
			exit(0);
		}
	cout << -1 << endl;

	return 0;
}