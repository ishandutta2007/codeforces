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
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()

template<typename T> bool uin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<typename T> bool uax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream & out = cerr) {
	while (begin != end) {
		out << (*begin) << ' ';
		begin++;
	}
	out << '\n';
}

template<class T> void output(T x, ostream & out = cerr) {
	output(all(x), out);
}

mt19937 rnd(time(NULL));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> g[200000], g1[200000];
	vector<pair<int, int>> vv(m);
	vector<int> ans(m);
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
		g1[v].push_back(i);
		g1[u].push_back(i);
		vv[i] = { v, u };
	}
	set<pair<int, int>> q;
	vector<bool> used(n, 1);
	vector<int> st(n);
	forn(i, n) {
		q.insert({ (int)g[i].size(), i });
		st[i] = (int)g[i].size();
	}
	for (int r = 0; r < m; ++r) {
		while (!q.empty() && q.begin()->first < k) {
			int i = q.begin()->second;
			q.erase(q.begin());
			used[i] = 0;
			forn(to, g[i].size())
				if (used[g[i][to]] && g1[i][to] + r < m) {
					q.erase({ st[g[i][to]], g[i][to] });
					st[g[i][to]]--;
					q.insert({ st[g[i][to]], g[i][to] });
				}
		}
		ans.push_back((int)q.size());
		int v = vv[m - r - 1].first, u = vv[m - r - 1].second;
		if (used[v] && used[u]) {
			q.erase({ st[v], v });
			st[v]--;
			q.insert({ st[v], v });
			q.erase({ st[u], u });
			st[u]--;
			q.insert({ st[u], u });
		}
	}
	reverse(all(ans));
	forn(i, m)
		cout << ans[i] << '\n';
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}