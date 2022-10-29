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
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

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
	n <<= 1;
	vector<int> a(n), pr(n, -1);
	forn(i, n)
		cin >> a[i];
	vector<pair<int, int>> k(m), b(n);
	forn(i, n) b[i] = { a[i], i };
	sort(all(b));
	reverse(all(b));
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		k[i] = { v, u };
		pr[v] = u;
		pr[u] = v;
	}
	int t;
	cin >> t;
	if (t == 1) {
		forn(i, m) {
			int v = k[i].x, u = k[i].y;
			if (a[v] < a[u]) swap(v, u);
			cout << v + 1 << endl;
			cin >> u;
		}
		int r = 0;
		while (1) {
			while (r < n && pr[b[r].y] != -1) r++;
			if (r >= n) break;
			cout << b[r].y + 1 << endl;
			int u;
			cin >> u;
			u--;
			pr[b[r].y] = pr[u] = 0;
		}
	}
	else {
		int v;
		int cnt = 0;
		while (cnt < n) {
			cin >> v;
			v--;
			if (pr[v] == -1) break;
			cout << pr[v] + 1 << endl;
			pr[pr[v]] = inf;
			pr[v] = inf;
			cnt += 2;
		}
		if (cnt < n) {
			forn(i, m) {
				if (pr[k[i].x] == inf) continue;
				int v = k[i].x, u = k[i].y;
				if (a[v] < a[u]) swap(v, u);
				cout << v + 1 << endl;
				cin >> u;
				cnt += 2;
			}
			pr[v] = 0;
			int r = 0;
			while (1) {
				while (r < n && pr[b[r].y] != -1) r++;
				if (r >= n) break;
				cout << b[r].y + 1 << endl;
				if (cnt == n - 2) break;
				int u;
				cin >> u;
				u--;
				pr[b[r].y] = pr[u] = 0;
				cnt += 2;
			}
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}