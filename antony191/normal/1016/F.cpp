#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
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

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()
//#define int ll

vector<int> p;
vector<ll> d, cl;
vector<pair<int, ll>> g[300'000];

void dfs(int v) {
	cl[v] = 1ll;
	for (auto i : g[v]) {
		int to = i.first;
		ll w = i.second;
		if (to == p[v]) continue;
		p[to] = v;
		d[to] = d[v] + w;
		dfs(to);
		cl[v] += cl[to];
	}
}

void answer(int m, int n) {
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
	}
	for (int i = 0; i < m; ++i)
		cout << d[n - 1] << '\n';
}
signed main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) {
		int v, u, w;
		cin >> v >> u >> w;
		v--; u--;
		g[v].push_back({ u, w * 1ll });
		g[u].push_back({ v, w * 1ll });
	}
	d.resize(n); p.resize(n); cl.resize(n);
	dfs(0);
	vector<int> order;
	for (int i = n - 1; i != 0; i = p[i]) order.push_back(i);
	order.push_back(0);
	reverse(all(order));
	for (int i = 0; i < (int)order.size() - 1; ++i) {
		if (cl[order[i]] - cl[order[i + 1]] >= 3) {
			answer(m, n);
			return 0;
		}
	}
	if (cl[n - 1] >= 3) {
		answer(m, n);
		return 0;
	}
	int k = (int)order.size();
	vector<ll> mx1(k - 1), mx2(k - 1);
	for (int i = 0; i < k - 1; ++i) {
		if (i > 0)
			mx1[i] = max(mx1[i - 1], d[order[i]]);
		for (auto j : g[order[i]])
			if (j.first != (i > 0 ? order[i - 1] : -1) && j.first != order[i + 1])
				mx1[i] = max(mx1[i], d[j.first]);
	}
	for (int i = k - 2; i + 1; --i) {
		if (i < k - 2)
			mx2[i] = max(mx2[i + 1], d[n - 1] - d[order[i + 1]]);
		for (auto j : g[order[i + 1]])
			if (j.first != (i < k - 2 ? order[i + 2] : -1) && j.first != order[i])
				mx2[i] = max(mx2[i], d[n - 1] - d[order[i + 1]] + j.second);
	}
	ll mx = 0;
	for (int i = 0; i < k - 1; ++i) {
		ll tmp = mx1[i] + mx2[i];
		if (cl[order[i]] - cl[order[i + 1]] == 1 && 
			cl[order[i + 1]] - (i == k - 2 ? 0 : cl[order[i + 2]]) == 1) {
			tmp = 0;
			if (i > 0) tmp = mx1[i - 1] + mx2[i];
			if (i < k - 2) tmp = max(tmp, mx1[i] + mx2[i + 1]);
		}
		mx = max(mx, tmp);
	}
	for (int i = 0; i < m; ++i) {
		ll x;
		cin >> x;
		cout << min(d[n - 1], mx + x) << '\n';
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}