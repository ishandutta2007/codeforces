#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <queue>
#include <random>
#include <map>
#include <array>
#include <bitset>
#include <unordered_map>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

const int N = 1e5 + 100;

int n, m;
int U[N], V[N];
vi in[N];
ll ans;
int deg[N];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v;
		deg[u]++; deg[v]++;
		if (u > v) {
			in[v].pb(i);
			U[i] = u; V[i] = v;
		}
		else {
			in[u].pb(i);
			U[i] = v; V[i] = u;
		}
	}
	for (int i = 0; i < n; i++) {
		ans += 1LL * sz(in[i]) * (deg[i] - sz(in[i]));
	}
	cout << ans << '\n';
	int q;
	cin >> q;
	while (q--) {
		int v; cin >> v; --v;
		int rem = sz(in[v]);
		for (int i : in[v]) {
			int u = U[i];
			ans -= (deg[v] - rem) + sz(in[u]);
			in[u].pb(i);
			rem--;
			ans += rem + (deg[u] - sz(in[u]));
			swap(U[i], V[i]);
		}
		in[v].clear();
		cout << ans << '\n';
	}
}