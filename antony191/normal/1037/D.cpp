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
	int n;
	cin >> n;
	vector<int> g[200'000];
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	forn(i, n) sort(all(g[i]));
	vector<int> a(n);
	forn(i, n) {
		cin >> a[i];
		a[i]--;
	}
	if (a[0] != 0)
		return cout << "No", 0;
	deque<int> q;
	q.push_back(0);
	int l = 0, r = 0;
	vector<bool> used(n, 0);
	while (!q.empty()) {
		int v = q.front();
		used[v] = 1;
		q.pop_front();
		if (v != a[l])
			return cout << "No", 0;
		if (r == l) r++;
		l++;
		int cnt = 0;
		for (auto to : g[v])
			if (!used[to])
				cnt++;
		if (r + cnt > n) return cout << "No", 0;
		for (int j = r; j < r + cnt; ++j) {
			int to = lower_bound(all(g[v]), a[j]) - g[v].begin();
			if (to >= (int)g[v].size() || g[v][to] != a[j]) return cout << "No", 0;
			if (used[g[v][to]]) return cout << "No", 0;
			used[g[v][to]] = 1;
			q.push_back(g[v][to]);
		}
		r += cnt;
	}
	cout << "Yes";
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}