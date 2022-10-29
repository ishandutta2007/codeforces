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
#define FOR(i, n) forn(i, n)
#define debug(x) std::cout << #x << ": " << x << '\n';
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

const int N = 1001;
int b[N][N];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n), cl(n + 1);
	forn(i, n) cin >> a[i];
	forn(i, n + 1) forn(j, n + 1) b[i][j] = -1;
	forn(i, n) {
		vector<int> cnt(n + 1), tmp[2];
		tmp[0].assign(n + 1, -1); tmp[1].assign(n + 1, -1);
		int cc = 0;
		forn(j, n + 1) cnt[cl[j]]++;
		forn(j, n + 1) {
			if (cnt[j] < 2) continue;
			int sum = 0;
			forn(k, n + 1) {
				if (cl[k] == j) {
					if (!sum) b[k][i] = 0;
					else b[k][i] = 1;
					sum++;
					if (sum > 1) break;
				}
			}
			a[i]--;
			forn(k, n + 1) {
				if (b[k][i] == -1) {
					if (a[i] > 0) b[k][i] = 1, a[i]--;
					else b[k][i] = 0;
				}
				if (tmp[b[k][i]][cl[k]] >= 0) cl[k] = tmp[b[k][i]][cl[k]];
				else {
					tmp[b[k][i]][cl[k]] = cc;
					cl[k] = cc++;
				}
			}
			break;
		}
		if (b[0][i] == -1)
			forn(k, n + 1) {
			if (k < a[i]) b[k][i] = 1;
			else b[k][i] = 0;
		}
	}
	cout << n + 1 << el;
	forn(i, n + 1) {
		forn(j, n) cout << b[i][j];
		cout << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
}