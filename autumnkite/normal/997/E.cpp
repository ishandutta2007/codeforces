#include <bits/stdc++.h>

const int N = 120005, LG = 17;

int n;
int a[N];
int p[N];

struct Interval {
	int l, r;

	Interval() {}

	Interval(int _l, int _r) : l(_l), r(_r) {}
};

Interval operator+(const Interval &a, const Interval &b) {
	return Interval(std::min(a.l, b.l), std::max(a.r, b.r));
}

int Log[N];
Interval st[LG][N];

void initST() {
	Log[1] = 0;
	for (int i = 2; i <= n; ++i) {
		Log[i] = Log[i >> 1] + 1;
	}
	for (int i = 1; i <= n; ++i) {
		st[0][i] = Interval(p[i], p[i]);
	}
	for (int j = 1; j < LG; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			st[j][i] = st[j - 1][i] + st[j - 1][i + (1 << (j - 1))];
		}
	}
}

Interval query(int l, int r) {
	int t = Log[r - l + 1];
	return st[t][l] + st[t][r - (1 << t) + 1];
}

struct Node {
	Interval I, ran, fsup, sup;
};

Node operator+(const Node &a, const Node &b) {
	Node res;
	res.I = a.I + b.I;
	res.ran = a.ran + b.ran;
	res.fsup = a.fsup + b.fsup;
	res.sup = a.fsup + b.sup;
	return res;
}

bool check(const Node &a) {
	return a.I.r - a.I.l == a.ran.r - a.ran.l;
}

int cnt;
bool type[N * 2];
Node nd[N * 2];
std::vector<int> E[N * 2];

int top, sta[N];
int fail[N];
Node fail_nd[N];

int rt;

int add(int u) {
	if (!top) {
		sta[++top] = u;
		fail[top] = 0;
		fail_nd[top] = nd[u];
		return 0;
	}
	int v = sta[top];
	Node tmp = nd[v] + nd[u];
	if (type[v] && !E[v].empty() && check(nd[E[v].back()] + nd[u])) {
		nd[v] = tmp;
		E[v].push_back(u);
		--top;
		return v;
	}
	if (check(tmp)) {
		nd[++cnt] = tmp;
		type[cnt] = true;
		E[cnt].push_back(v);
		E[cnt].push_back(u);
		--top;
		return cnt;
	}
	if (tmp.sup.r > nd[u].I.r) {
		sta[++top] = u;
		fail[top] = top - 1;
		fail_nd[top] = nd[u];
		return 0;
	}
	int t = top;
	tmp = nd[u];
	do {
		tmp = fail_nd[t] + tmp;
		t = fail[t];
	} while (tmp.sup.r <= nd[u].I.r && !check(tmp));
	if (check(tmp)) {
		nd[++cnt] = tmp;
		type[cnt] = false;
		for (int i = t + 1; i <= top; ++i) {
			E[cnt].push_back(sta[i]);
		}
		E[cnt].push_back(u);
		top = t;
		return cnt;
	}
	sta[++top] = u;
	fail[top] = t;
	fail_nd[top] = tmp;
	return 0;
}

int dep[2 * N];
int fa[2 * N][LG + 1];
int num[2 * N];
long long sum[2 * N];
long long pre[2 * N];

void dfs(int u) {
	dep[u] = dep[fa[u][0]] + 1;
	for (int i = 1; i <= LG; ++i) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	int len = E[u].size();
	if (type[u] && len) {
		sum[u] = 1ll * len * (len - 1) / 2;
	} else {
		sum[u] = 1;
	}
	for (int i = 0; i < len; ++i) {
		int v = E[u][i];
		num[v] = i;
		fa[v][0] = u;
		dfs(v);
		sum[u] += sum[v];
		pre[v] = sum[u];
	}
}

long long sum1[2 * N], sum2[2 * N];

void dfs2(int u) {
	int len = E[u].size();
	long long now = 0;
	for (int i = len - 1; i >= 0; --i) {
		int v = E[u][i];
		sum1[v] = sum1[u] + now;
		now += sum[v] + (type[u] ? len - i - 1 : 0);
	}
	now = 0;
	for (int i = 0; i < len; ++i) {
		int v = E[u][i];
		sum2[v] = sum2[u] + now;
		now += sum[v] + (type[u] ? i : 0);
	}
	for (int v : E[u]) {
		dfs2(v);
	}
}

std::pair<int, int> LCA(int u, int v) {
	if (dep[u] > dep[v]) {
		for (int i = LG; ~i; --i) {
			if (dep[fa[u][i]] >= dep[v]) {
				u = fa[u][i];
			}
		}
	} else if (dep[u] < dep[v]) {
		for (int i = LG; ~i; --i) {
			if (dep[fa[v][i]] >= dep[u]) {
				v = fa[v][i];
			}
		}
	}
	if (u == v) {
		return std::make_pair(u, v);
	}
	for (int i = LG; ~i; --i) {
		if (fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return std::make_pair(u, v);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	a[1] = n + 2, p[n + 2] = 1;
	a[n + 2] = 1, p[1] = n + 2;
	for (int i = 2; i <= n + 1; ++i) {
		std::cin >> a[i];
		++a[i];
		p[a[i]] = i;
	}
	n += 2;

	initST();

	cnt = n;
	for (int i = 1; i <= n; ++i) {
		nd[i].I = Interval(i, i);
		nd[i].ran = Interval(a[i], a[i]);
		if (i < n) {
			int l = a[i], r = a[i + 1];
			if (l > r) {
				std::swap(l, r);
			}
			nd[i].fsup = query(l, r);
		} else {
			nd[i].fsup = Interval(n + 1, 0);
		}
		nd[i].sup = Interval(n + 1, 0);
		type[i] = true;
	}
	for (int i = 1; i <= n; ++i) {
		int x = i;
		while (x) {
			x = add(x);
		}
	}

	rt = sta[1];
	dfs(rt);
	dfs2(rt);

	int q;
	std::cin >> q;
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		r += 2;
		std::pair<int, int> son = LCA(l, r);
		int u = fa[son.first][0];
		long long ans = sum1[l] - sum1[son.first] + sum2[r] - sum2[son.second];
		ans += pre[E[u][num[son.second] - 1]] - pre[son.first];
		if (type[u]) {
			ans += 1ll * (num[son.second] - num[son.first] - 1) * (num[son.second] - num[son.first] - 2) / 2;
		}
		std::cout << ans << "\n";
	}
}
/*
5
1 3 2 5 4
1
1 1
*/