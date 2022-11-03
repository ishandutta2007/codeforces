#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <limits>
#include <ctime>
#include <cassert>

#define pb push_back
#define mp make_pair
#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#ifndef _getchar_nolock
#define _putchar_nolock putchar_unlocked
#define _getchar_nolock getchar_unlocked
#endif
//#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:536870912")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <char> vc;

const ld EPS = 1e-8;
const int N = (int)5e5 + 10;
const int INF = (int)2e9;
const int MOD = 998244353;

int timer = 0;

void dfs0(int v, vvi& g, vi& tin, vi& tout) {
	tin[v] = timer++;
	for (int u : g[v]) {
		dfs0(u, g, tin, tout);
	}
	tout[v] = timer++;
	return;
}

void dfs(int v, vvi& g, vi& tin, vi& tout, set<pii>& s, vector<pair<int, pii>>& st, int& ans) {

	if (s.empty())
		s.insert({ tin[v], tout[v] });
	else {
		auto it = s.upper_bound({ tin[v], 0 });
		if (it == s.end() || it->first > tout[v]) {
			if (it != s.begin()) {
				--it;
				if (it->second > tout[v]) {
					st.push_back({ 1, *it });
					s.erase(it);
				}
			}
			s.insert({ tin[v], tout[v] });
			st.push_back({ 0, {tin[v], tout[v]} });
		}
	}
	if (g[v].empty()) {
		ans = max(ans, (int)s.size());
		return;
	}
	for (int u : g[v]) {
		int sz = st.size();
		dfs(u, g, tin, tout, s, st, ans);
		while (st.size() != sz) {
			if (st.back().first == 0)
				s.erase(st.back().second);
			else
				s.insert(st.back().second);
			st.pop_back();
		}
	}
	return;
}

void solve() {
	int n;
	cin >> n;
	vvi a(n);
	vvi b(n);
	for (int i = 0; i < n - 1; ++i) {
		int x;
		cin >> x;
		--x;
		a[x].push_back(i + 1);
	}
	for (int i = 0; i < n - 1; ++i) {
		int x;
		cin >> x;
		--x;
		b[x].push_back(i + 1);
	}
	vi tin(n), tout(n);
	timer = 0;
	dfs0(0, b, tin, tout);
	set<pii> s;
	vector<pair<int, pii>> st;
	int ans = 1;
	dfs(0, a, tin, tout, s, st, ans);
	cout << ans << endl;
	return;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();

	return 0;
}