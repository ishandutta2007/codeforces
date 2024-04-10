#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

const int MX = 1e7 + 100;
const int MAXN = 120000;
const int LOG = 20;

int cc[MX];
int bb[MX];
vector<int> prime;
int tin[MAXN];
int tout[MAXN];
vector<int> eds[MAXN];
int tm1;
int n;
ll ans[MAXN];
int up[MAXN][LOG];



void dfs1(int v, int p) {
	tin[v] = tm1++;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		up[u][0] = v;
		dfs1(u, v);
	}
	tout[v] = tm1;
}

int is_p(int a, int b) {
	return tin[a] <= tin[b] && tin[b] < tout[a];
}

int lca(int a, int b) {
	if (is_p(a, b))
		return a;
	if (is_p(b, a))
		return b;
	for (int i = LOG - 1; i >= 0; --i) {
		if (!is_p(up[a][i], b))
			a = up[a][i];
	}
	return up[a][0];
}


vector<pair<int, int> > ad[MAXN];
vector<pair<int, int> > rm[MAXN];
int a[MAXN];

void dfs2(int v, int p) {
	int now = a[v];
	int prev = 0;
	int cur = 1;
	while (now != 1) {
		int x = bb[now];
		if (x == 0)
			x = now;
		if (x != prev)
			cur = 1, prev = x;
		cur *= x;
		now /= x;
		++cc[cur];
	}
	for (auto pr: ad[v]) {
		int now = pr.first;
		int prev = 0;
		int cur = 1;
		ll ml = 1;
		while (now != 1) {
			int x = bb[now];
			if (x == 0)
				x = now;
			if (x != prev)
				cur = 1, prev = x;
			cur *= x;
			now /= x;
			ml = (ml * pw(x, cc[cur])) % MOD;
		}
		ans[pr.second] = (ans[pr.second] * ml) % MOD;
	}
	for (auto pr: rm[v]) {
		int now = pr.first;
		int prev = 0;
		int cur = 1;
		ll ml = 1;
		while (now != 1) {
			int x = bb[now];
			if (x == 0)
				x = now;
			if (x != prev)
				cur = 1, prev = x;
			cur *= x;
			now /= x;
			ml = (ml * pw(x, cc[cur])) % MOD;
		}
		ml = pw(ml, MOD - 2);
		ml = ml * ml % MOD;
		ans[pr.second] = (ans[pr.second] * ml) % MOD;
	}
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs2(u, v);
	}
	now = a[v];
	prev = 0;
	cur = 1;
	while (now != 1) {
		int x = bb[now];
		if (x == 0)
			x = now;
		if (x != prev)
			cur = 1, prev = x;
		cur *= x;
		now /= x;
		--cc[cur];
	}
}
int gcd(int a, int b) {
	while (b) {
		int q = a % b;
		a = b;
		b = q;
	}
	return a;
}


int main() {
	for (int i = 2; i < MX; ++i) {
		if (bb[i] == 0)
			prime.push_back(i);
		for (ll x: prime) {
			if (x > i || x * i >= MX)
				break;
			bb[x * i] = x;
		}
	}
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0, -1);
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j < MAXN; ++j) {
			up[j][i] = up[up[j][i - 1]][i - 1];
		}
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		--x, --y;
		int l = lca(x, y);
		ans[i] = gcd(a[l], w);
		ad[x].emplace_back(w, i);
		ad[y].emplace_back(w, i);
		rm[l].emplace_back(w, i);
	}
	dfs2(0, -1);
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << "\n";
	}
}