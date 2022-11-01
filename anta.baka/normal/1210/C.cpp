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
const int LG = 18;

int n;
vi g[N];
ll x[N];
ll ans;
int dep[N];
int pred[N];

int up[LG][N];
ll gc[LG][N];

const int mod = 1e9 + 7;

ll gcd(ll a, ll b) {
	return (b ? gcd(b, a % b) : a);
}

void dfs(int v, int p) {
	pred[v] = (v == 0 ? -1 : p);
	up[0][v] = p;
	gc[0][v] = gcd(x[v], (pred[v] == -1 ? 0 : x[pred[v]]));
	for (int i = 1; i < LG; i++) {
		up[i][v] = up[i - 1][up[i - 1][v]];
		gc[i][v] = gcd(gc[i - 1][v], gc[i - 1][up[i - 1][v]]);
	}
	int u = v;
	ll val = 0;
	while (u != -1) {
		val = gcd(val, x[u]);
		int st = u;
		for (int i = LG - 1; i >= 0; i--) {
			if (val == 0) {
				if (gc[i][u] == 0) {
					u = up[i][u];
				}
			}
			else if (gc[i][u] % val == 0) {
				u = up[i][u];
			}
		}
		ans = (ans + val * (dep[st] - dep[u] + 1)) % mod;
		//cout << "! " << v + 1 << ' ' << u + 1 << ' ' << val << endl;
		u = pred[u];
	}
	for (int to : g[v]) if(to != p) dep[to] = dep[v] + 1, dfs(to, v);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v; g[u].pb(v); g[v].pb(u);
	}
	dfs(0, 0);
	//for (int i = 0; i < 3; i++, cout << endl) for (int j = 0; j < n; j++) cout << gc[i][j] << ' ';
	//for (int i = 0; i < n; i++) cout << sum[i] << ' '; cout << endl;
	cout << ans;
}