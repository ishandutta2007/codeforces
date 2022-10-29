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

vector<int> g[500001], order, used;
void dfs(int v) {
	used[v] = 1;
	for (auto to : g[v])
		if (!used[to])
			dfs(to);
	order.push_back(v);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		forn(i, n + 1) {
			g[i].clear();
			g[i].shrink_to_fit();
		}
		vector<int> a(n);
		vector<pair<int, int>> p, st;
		forn(i, n) {
			cin >> a[i];
			a[i]--;
			if (a[i] >= 0) {
				p.emplace_back(i, a[i]);
				g[i].push_back(a[i]);
			}
		}
		sort(all(p));
		if (p.empty()) {
			forn(i, n) cout << i + 1 << ' ';
			cout << el;
			continue;
		}
		st.push_back(p[0]);
		bool good = 1;
		firn(i, p.size()) {
			while (!st.empty() && st.back().y <= p[i].x) {
				st.pop_back();
			}
			if (!st.empty() && p[i].y > st.back().y) {
				good = 0;
				break;
			}
			if (!st.empty()) {
				g[p[i].x].push_back(st.back().x);
				if (p[i].y < st.back().y) g[p[i].y].push_back(st.back().x);
			}
			st.push_back(p[i]);
		}
		if (!good) {
			cout << -1 << el;
			continue;
		}
		order.clear();
		used.assign(n + 1, 0);
		dfs(n);
		forn(i, n) {
			if (!used[i] && !g[i].empty()) dfs(i);
		}
		//reverse(all(order));
		vector<int> ans(n + 1, -1);
		forn(i, order.size()) {
			ans[order[i]] = n - i;
		}
		int cnt = 0;
		forn(i, n)
			if (ans[i] == -1) ans[i] = cnt++;
		forn(i, n) cout << ans[i] + 1 << ' ';
		cout << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}