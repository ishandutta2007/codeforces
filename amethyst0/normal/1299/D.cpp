#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <fstream>
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

map <ll, map <int, ll> > ed;
int nx[500][500];
bool bad[500][500];

ll go(ll mask, int x) {
	if (ed[mask].count(x)) {
		return ed[mask][x];
	}
	
	ll to = mask;

	for (int i = 0; i < (1 << 5); i++) {
		if ((mask >> (ll)i) & 1) {
			to |= (1ll << (ll)(i ^ x));
		}
	}

	return ed[mask][x] = to;
}

vector <ll> g;
map <ll, int> num;

const int maxn = (int)1e5 + 10;

bool used[maxn];
vector <pii> red[maxn];
int com[maxn];
int up[maxn];
int pr[maxn];
ll cur[maxn];
bool ch[maxn];
ll gl[maxn];
int h[maxn];

void dfs(int v, int par, int c, int val, int hh = 1) {
	up[v] = val;
	used[v] = true;
	com[v] = c;
	pr[v] = par;
	h[v] = hh;

	for (auto[u, x] : red[v]) {
		if (u == par) {
			continue;
		}
		if (!used[u]) {
			dfs(u, v, c, val ^ x, hh + 1);
		}
		else if (u == 1) {
			gl[c] = go(1, val ^ x);
		}
		else if (h[v] > h[u]) {
			int y = val ^ x ^ up[u];
			if ((cur[c] >> (ll)y) & 1) {
				ch[c] = false;
			}
			else {
				cur[c] = go(cur[c], y);
			}
		}
	}
}

vector <ll> cyc;
vector <ll> ms;

const int mod = (int)1e9 + 7;

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int dp[2][500];

int main() {
	queue <ll> q;

	q.push(1);
	ed[1] = map <int, ll>();

	while (!q.empty()) {
		ll mask = q.front();
		q.pop();

		for (int i = 0; i < (1 << 5); i++) {
			ll to = go(mask, i);

			if (!ed.count(to)) {
				q.push(to);
				ed[to] = map <int, ll>();
			}
		}
	}

	int ps = 0;

	for (auto f : ed) {
		g.push_back(f.first);
		num[f.first] = ps++;
	}

	for (int i = 0; i < ps; i++) {
		for (int j = 0; j < ps; j++) {
			ll to = g[i];

			bool ok = true;

			for (int k = 1; k < (1 << 5); k++) {
				if ((g[j] >> (ll)k) & 1) {
					to = go(to, k);
				}

				if ((g[j] >> (ll)k) & 1) {
					if ((g[i] >> (ll)k) & 1) {
						ok = false;
					}
				}
			}

			bad[i][j] = !ok;
			nx[i][j] = num[to];
		}
	}

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		red[x].push_back(mp(y, w));
		red[y].push_back(mp(x, w));
	}

	used[1] = true;

	for (auto [u, w] : red[1]) {
		if (!used[u]) {
			cur[u] = 1;
			gl[u] = -1;
			ch[u] = true;
			dfs(u, 1, u, w);
			if (ch[u]) {
				cyc.push_back(gl[u]);
				ms.push_back(cur[u]);
			}
		}
	}

	dp[0][0] = 1;
	int it = 0;

	for (int i = 0; i < (int)cyc.size(); i++) {
		memset(dp[it ^ 1], 0, sizeof dp[it ^ 1]);
		int numb = num[ms[i]];
		int numbgl = -1;
		bool ok = false;
		int un = numb;
		int cf = 1;

		if (cyc[i] != -1) {
			cf = 2;
		}

		if (cyc[i] != -1 && cyc[i] != 1) {
			numbgl = num[cyc[i]];
			ok = !bad[numb][numbgl];
			un = nx[numb][numbgl];
		}

		for (int j = 0; j < (int)g.size(); j++) {
			dp[it ^ 1][j] = add(dp[it ^ 1][j], dp[it][j]);

			if (!bad[j][numb]) {
				int to = nx[j][numb];
				dp[it ^ 1][to] = add(dp[it ^ 1][to], mul(dp[it][j], cf));
			}

			if (ok && !bad[j][un]) {
				int to = nx[j][un];
				dp[it ^ 1][to] = add(dp[it ^ 1][to], dp[it][j]);
			}
		}

		it ^= 1;
	}

	int ans = 0;

	for (int i = 0; i < (int)g.size(); i++) {
		ans = add(ans, dp[it][i]);
	}

	cout << ans << '\n';
}