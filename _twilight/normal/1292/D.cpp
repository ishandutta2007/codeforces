#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>

const int N = 5005;

typedef vector<int> vec;

int num;
int mp[N];
int pri[N], pid[N];

void Euler(int n) {
	static bitset<N> vis;
	pid[1] = -1;
	for (int i = 2; i <= n; i++) {
		if (!vis.test(i)) {
			pid[i] = num;
			pri[num++] = i;
			mp[i] = i;
		}
		for (int *p = pri, *_ = pri + num, x; p != _ && (x = *p * i) <= n; p++) {
			vis.set(x);
			mp[x] = *p;
			if (!(i % *p))
				break;
		}
	}
}

vec factor(int n, vec num) {
	while (n > 1) {
		int p = mp[n];
		num[pid[p]]++;
		n /= p;
	}
	return num;
}

int n;
vec fac[N];
vector<vec> stkv;
vector<int> stkp;
vector<int> id (N);
vector<pii> G[N << 1];
int c[N << 1], sz[N << 1], d[N << 1];

int dfs(int p, int fa) {
	sz[p] = c[p];
	for (auto par : G[p]) {
		int e = par.first;
		if (e ^ fa) {
			sz[p] += dfs(e, p);
		}
	}
	return sz[p];	
}

int get_g(int p, int fa) {
	for (auto _ : G[p]) {
		int e = _.first;
		if (e != fa && sz[e] * 2 > n) {
			return get_g(e, p);
		}
	}
	return p;
}

void dfs(int p, int fa, int dis) {
	d[p] = dis;
	for (auto _ : G[p]) {
		int e = _.first;
		int w = _.second;
		if (e ^ fa) {
			dfs(e, p, dis + w);
		}
	}
}

int main() {
	Euler(5000);
	fac[1] = vec(num, 0);
	for (int i = 2; i <= 5000; i++) {
		fac[i] = factor(i, fac[i - 1]);
	}
	for (int i = 2; i <= 5000; i++)
		reverse(fac[i].begin(), fac[i].end());
	id[1] = 1;
	int cnt = 1;
	
	auto lca = [&] (vec& a, vec& b) {
		vec rt (num, 0);
		for (int i = 0; i < num; i++) {
			if (a[i] == b[i]) {
				rt[i] = a[i];
			} else {
				rt[i] = min(a[i], b[i]);
				break;
			}
		}
		return rt;
	};
	auto dist = [&] (vec& a, vec& b) {
		int x = 0;
		for (auto y : a)
			x += y;
		for (auto y : b)
			x -= y;
		return (x < 0) ? -x : x;
	};
	
	stkv.push_back(fac[1]);
	stkp.push_back(1);
	for (int i = 2; i <= 5000; i++) {
		vec g = lca(fac[i - 1], fac[i]);
		vector<int> P;
		vector<vec> V;
		while (stkv.back() > g) {
			P.push_back(stkp.back());
			V.push_back(stkv.back());
			stkv.pop_back();
			stkp.pop_back();
		}
		if (stkv.back() != g) {
			stkv.push_back(g);
			stkp.push_back(++cnt);
		}
		P.push_back(stkp.back());
		V.push_back(stkv.back());
		stkv.push_back(fac[i]);
		stkp.push_back(id[i] = ++cnt);
		for (int i = 1; i < (signed) P.size(); i++) {
			int u = P[i], v = P[i - 1], w = dist(V[i - 1], V[i]);
			G[u].emplace_back(v, w);
			G[v].emplace_back(u, w);
		}
	}
	for (int i = 0; i < (signed) stkp.size() - 1; i++) {
		int u = stkp[i], v = stkp[i + 1], w = dist(stkv[i], stkv[i + 1]);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	
	}
	
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		x = max(x, 1);
		c[id[x]]++;	
	}

	dfs(1, 0);
	int g = get_g(1, 0);
	dfs(g, 0, 0);
	long long ans = 0;
	for (int i = 1; i <= cnt; i++)
		ans += 1ll * c[i] * d[i];
	printf("%lld\n", ans);
	return 0;
}