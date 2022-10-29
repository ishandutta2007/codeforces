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
const ll llinf = 3e18, mod = 1000'000'007;
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

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int t = (n - k) / 2;
	if (k <= t) {
		forn(i, t) cout << 0;
		if (k == 2) cout << "11";
		else if (k == 1) cout << 1;
		else {
			cout << 1;
			forn(i, k - 2) cout << 0;
			cout << 1;
		}
		forn(i, t) cout << 0;
	}
	else {
		int p = k % (t + 1);
		if (p < 0) p += t + 1;
		if (!p) {
			if (n == k) {
				forn(i, n) cout << 0;
			}
			else {
				forn(i, t) cout << 0;
				forn(i, k / (t + 1)) {
					cout << 1;
					forn(j, t) cout << 0;
				}
				cout << 1;
				forn(i, t - 1) cout << 0;
			}
		}
		else {
			forn(i, p - 1) cout << 1;
			forn(i, t + 1 - p) cout << 0;
			forn(i, k / (t + 1)) {
				forn(j, p) cout << 1;
				forn(j, t + 1 - p) cout << 0;
			}
			forn(j, p) cout << 1;
			forn(j, t + 1 - p) cout << 0;
			forn(j, p - 1) cout << 1;
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}