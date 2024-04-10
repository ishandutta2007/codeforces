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
	int n, m;
	cin >> n >> m;
	vector<int> a[10], pos[10];
	forn(i, m) {
		a[i].resize(n);
		pos[i].resize(n);
		forn(j, n)
			cin >> a[i][j], pos[i][a[i][j] - 1] = j;
	}
	vector<ll> ans(n, 0);
	for (int i = n - 1; i + 1; --i) {
		int v = a[0][i];
		v--;
		ans[v] = 1ll;
		if (i == n - 1) continue;
		int u = a[0][i + 1] - 1;
		bool bad = 0;
		firn(j, m)
			if (!(pos[j][v] + 1 == pos[j][u])) {
				bad = 1;
				break;
			}
		if (!bad) ans[v] += ans[u];
	}
	ll sum = 0;
	forn(i, n) sum += ans[i] * 1ll;
	cout << sum;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}