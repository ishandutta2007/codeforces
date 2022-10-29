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
vector<int> a, pos;
vector<pair<int, int>> ans;
void sp(int l, int r) {
	ans.push_back({ l + 1, r + 1 });
	swap(a[l], a[r]);
	pos[a[l]] = l;
	pos[a[r]] = r;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	a.resize(n); pos.resize(n);
	forn(i, n) {
		cin >> a[i];
		a[i]--;
		pos[a[i]] = i;
	}
	if (pos[0] != 0) {
		if (pos[0] < n / 2) {
			sp(pos[0], n - 1);
			sp(n - 1, 0);
		}
		else {
			sp(0, pos[0]);
		}
	}
	firn(i, n - 1) {
		if (pos[i] == i) continue;
		if (i < n / 2) {
			if (pos[i] < n / 2) {
				int t = pos[i];
				sp(t, n - 1);
				sp(n - 1, i);
			}
			else {
				int t = pos[i];
				if (t >= i + n / 2) sp(t, i);
				else {
					sp(t, 0);
					sp(0, n - 1);
					sp(n - 1, i);
					sp(n - 1, 0);
					sp(0, t);
				}
			}
		}
		else {
			int t = pos[i];
			sp(t, 0);
			sp(0, i);
			sp(0, t);
		}
	}
	bool ok = 1;
	forn(i, n) if (pos[i] != i) ok = 0;
	if (!ok) cerr << "bad" << el;
	cout << (int)ans.size() << el;
	forn(i, ans.size()) cout << ans[i].x << ' ' << ans[i].y << el;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}