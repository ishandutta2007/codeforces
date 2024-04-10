#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)3e5 + 10;
int p[maxn];
int c[maxn];

int pr[maxn];
int e[maxn][27];
int num[maxn];
int dp[maxn][27];
bool good[maxn];

vector <int> ed[maxn];
vector <int> edg[maxn];
int minh[maxn], maxh[maxn];

void dfs(int v) {
	if ((int)ed[v].size() == 1) {
		
	}
	else {
		int u = v;

		while (u == v || (u != 1 && (int)ed[u].size() == 1)) {
			num[u] = v;
			e[v][c[u]]++;
			u = p[u];
		}

		edg[u].push_back(v);
		pr[v] = u;
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		dfs(u);
	}
}

void recalc(int v) {
	if (edg[v].empty()) {
		good[v] = true;
		return;
	}

	if ((int)edg[v].size() == 1) {
		int to = edg[v][0];
		
		for (int i = 0; i < 27; i++) {
			dp[v][i] = dp[to][i] + e[to][i];
		}

		good[v] = good[to];
	}
	else {
		int to1 = edg[v][0];
		int to2 = edg[v][1];

		if (!good[to1] || !good[to2]) {
			good[v] = false;
			return;
		}

		int cnt = 0;

		for (int i = 0; i < 27; i++) {
			int x = dp[to1][i] + e[to1][i];
			int y = dp[to2][i] + e[to2][i];

			if (i < 26) {
				cnt += max(x, y) - x;

				dp[v][i] = max(x, y);
			}
			else {
				dp[v][i] = x;
			}
		}

		if (dp[v][26] >= cnt) {
			dp[v][26] -= cnt;
			good[v] = true;
		}
		else {
			good[v] = false;
		}
	}
}

void build(int v) {
	for (int i = 0; i < (int)edg[v].size(); i++) {
		int to = edg[v][i];

		build(to);
	}

	recalc(v);
}

bool check(int v) {
	if (ed[v].empty()) {
		minh[v] = maxh[v] = 0;
		return true;
	}

	minh[v] = (int)1e9;
	maxh[v] = 0;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (!check(u)) {
			return false;
		}

		minh[v] = min(minh[v], minh[u] + 1);
		maxh[v] = max(maxh[v], maxh[u] + 1);
	}

	if (minh[v] != maxh[v]) {
		return false;
	}

	return true;
}

int main() {
	int n, q;

	cin >> n >> q;
	//n = (1 << 18) - 1;
	//q = 0;

	for (int i = 2; i <= n; i++) {
		char f;
		scanf("%d %c", &p[i], &f);
		
		ed[p[i]].push_back(i);
		
		if ('a' <= f && f <= 'z') {
			c[i] = f - 'a';
		}
		else {
			c[i] = 26;
		}
	}

	bool fl = check(1);

	dfs(1);
	build(1);

	for (int i = 2; i <= n; i++) {
		if ((int)edg[i].size() == 1) {
			throw 1;
		}
	}

	while (q--) {
		int x;
		char f;

		scanf("%d %c", &x, &f);
		int cur = 26;

		if (!fl) {
			printf("Fou\n");
			continue;
		}

		if ('a' <= f && f <= 'z') {
			cur = f - 'a';
		}

		int y = x;

		x = num[x];
		e[x][c[y]]--;
		c[y] = cur;
		e[x][c[y]]++;

		while (x != 1) {
			x = pr[x];
			recalc(x);
		}

		if (!good[1]) {
			printf("Fou\n");
		}
		else {
			ll ans = 0;

			for (int i = 0; i < 26; i++) {
				ans += (ll)(i + 1) * (dp[1][i] + dp[1][26]);
			}

			printf("Shi %lld\n", ans);
		}
	}

	//system("pause");
}