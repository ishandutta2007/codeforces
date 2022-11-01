#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <map>
#include <iomanip>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <random>
#include <queue>
#include <cstring>
#include <chrono>

#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;
using pll = pair<ll, ll>;

ll gcd(ll a, ll b) {
	return (b ? gcd(b, a % b) : a);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<ll> c(n);
		for (auto& x : c) {
			cin >> x;
		}
		vector<vector<ll>> adj(n);
		while (m--) {
			int u, v;
			cin >> u >> v;
			--u; --v;
			adj[v].pb(u);
		}
		map<vector<ll>, ll> mapik;
		for (int u = 0; u < n; u++) {
			if (!adj[u].empty()) {
				sort(all(adj[u]));
				mapik[adj[u]] += c[u];
			}
		}
		ll g = 0;
		for (auto p : mapik) {
			g = gcd(p.second, g);
		}
		cout << g << '\n';
	}
}