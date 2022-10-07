#include <bits/stdc++.h>

const int N = 300005, LG = 19;

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

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		std::cin >> x >> y;
		a[x] = y;
		p[y] = x;
	}

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

	long long ans = n;
	for (int i = 1; i <= cnt; ++i) {
		if (!E[i].empty()) {
			if (type[i]) {
				ans += 1ll * E[i].size() * ((int)E[i].size() - 1) / 2;
			} else {
				++ans;
			}
		}
	}
	std::cout << ans << "\n";
}