#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = (int)1e5 + 10;

int tin[maxn];
vector <int> ed[maxn];
ld t[maxn];
ld p[maxn];
int tt = 0;
int pp[maxn];

void dfs(int v, int pr) {
	pp[v] = pr;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u == pr) {
			swap(ed[v][i], ed[v].back());
			ed[v].pop_back();
			i--;
			continue;
		}

		if (u != pr) {
			tin[u] = tt++;
		}
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		dfs(u, v);
	}
}

ld getsum(int pos) {
	ld ans = 0;

	for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		ans += t[pos];
	}

	return ans;
}

ld solve(int v) {
	int k = (int)ed[v].size();
	
	ld sums = 0;

	ld ans = k * p[v];

	if (!ed[v].empty()) {
		sums = getsum(tin[ed[v].back()]) - getsum(tin[ed[v][0]] - 1);
	}

	ans += (1 - p[v]) * sums;

	return ans;
}

void change(int pos, ld x) {
	for ( ; pos < maxn; pos |= pos + 1) {
		t[pos] += x;
	}
}

int main() {
	int n;

	cin >> n;

	ld sums = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%lf", &p[i]);
		sums += p[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		x++;
		y++;

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	dfs(1, 0);

	for (int i = 2; i <= n; i++) {
		change(tin[i], p[i]);
	}

	ld ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += solve(i);
	}

	int q;

	cin >> q;

	while (q--) {
		int x;
		ld prob;

		scanf("%d %lf", &x, &prob);
		sums -= p[x + 1];
		sums += prob;

		x++;

		ans -= solve(x);
		if (x != 1) {
			ans -= solve(pp[x]);
			change(tin[x], -p[x] + prob);
		}

		p[x] = prob;

		ans += solve(x);

		if (x != 1) {
			ans += solve(pp[x]);
		}

		printf("%.10lf\n", ans - sums + 1);
	}

	return 0;
}