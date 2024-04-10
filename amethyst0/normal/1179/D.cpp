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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)5e5 + 10;
vector <int> ed[maxn];
ll sz[maxn];
ll dp[maxn];
int n;

bool cmp(int a, int b) {
	return sz[a] < sz[b];
}

struct vt {
	ll x, y;

	vt() {

	}

	vt(ll x, ll y) : x(x), y(y) {

	}
};

vt operator -(vt a, vt b) {
	a.x -= b.x;
	a.y -= b.y;

	return a;
}

vt operator +(vt a, vt b) {
	a.x += b.x;
	a.y += b.y;

	return a;
}

ll operator *(vt a, vt b) {
	return a.x * b.x + a.y * b.y;
}

ll operator %(vt a, vt b) {
	return a.x * b.y - a.y * b.x;
}

vector <vt> f;

void add(ll x, ll y) {
	vt a = vt(x, y);

	int len = (int)f.size();

	if (!f.empty() && f.back().x > x) {
		throw 1;
	}

	while (len >= 2 && (a - f[len - 2]) % (f[len - 1] - f[len - 2]) >= 0) {
		f.pop_back();
		len--;
	}

	f.push_back(a);
}

ll get_best(ll x, ll y) {
	vt a = vt(x, y);

	int l = 0;
	int r = (int)f.size() - 1;

	while (l != r) {
		int m = (l + r) >> 1;

		ll v1 = a * f[m];
		ll v2 = a * f[m + 1];

		if (v2 <= v1) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}

	return a * f[l];
}

ll go(int v, int p) {
	ll ans = (ll)1e18;
	sz[v] = 1;
	dp[v] = (ll)1e18;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u == p) {
			continue;
		}

		ans = min(ans, go(u, v));
		sz[v] += sz[u];
	}

	f.clear();

	sort(ed[v].begin(), ed[v].end(), cmp);

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u == p) {
			continue;
		}

		ll res = dp[u] + (ll)(n - sz[u]) * (n - sz[u] - 1) / 2;

		ans = min(ans, res);

		if (!f.empty()) {
			ll g = get_best(sz[u], 1);
			ans = min(ans, g + (ll)sz[u] * (sz[u] + 1) / 2 - (ll)sz[u] * n + dp[u]);
		}

		add(sz[u], res);

		ll cur = dp[u] + (ll)(sz[v] - sz[u] - 1) * (sz[v] - sz[u]) / 2;
		dp[v] = min(dp[v], cur);
	}

	dp[v] = min(dp[v], (ll)sz[v] * (sz[v] - 1) / 2);

	return ans;
}

int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	ll ans = (ll)n * (n - 1) - go(1, -1);

	cout << ans << endl;

	//system("pause");

	return 0;
}