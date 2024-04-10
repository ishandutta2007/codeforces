#include <bits/stdc++.h>

const int N = 1000005;

struct leftist_tree {
	int cnt;
	int top, rub[N];
	int ls[N], rs[N], dis[N], sz[N];
	int val[N];

	leftist_tree() {
		cnt = top = 0;
	}

	int new_node(int v) {
		int u = top ? rub[top--] : ++cnt;
		ls[u] = rs[u] = 0;
		dis[u] = 0;
		sz[u] = 1;
		val[u] = v;
		return u;
	}

	int merge(int u, int v) {
		if (!u || !v) {
			return u | v;
		}
		if (val[u] < val[v]) {
			std::swap(u, v);
		}
		rs[u] = merge(rs[u], v);
		if (dis[ls[u]] < dis[rs[u]]) {
			std::swap(ls[u], rs[u]);
		}
		if (!rs[u]) {
			dis[u] = 0;
		} else {
			dis[u] = dis[rs[u]] + 1;
		}
		sz[u] = sz[ls[u]] + sz[rs[u]] + 1;
		return u;
	}

	int pop(int u) {
		rub[++top] = u;
		return merge(ls[u], rs[u]);
	}
	
	int size(int u) {
		return sz[u];
	}
} T;

int n;
int a[N], b[N];

int top, pos[N], rt[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		a[i] = -a[i];
	}
	for (int i = 1; i <= n; ++i) {
		rt[++top] = T.new_node(a[i]);
		pos[top] = i;
		while (top > 1 && T.val[rt[top]] < T.val[rt[top - 1]]) {
			--top;
			rt[top] = T.merge(rt[top], rt[top + 1]);
			pos[top] = i;
			while (T.size(rt[top]) > (i - pos[top - 1] + 1) / 2) {
				rt[top] = T.pop(rt[top]);
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= top; ++i) {
		for (int j = pos[i - 1] + 1; j <= pos[i]; ++j) {
			b[j] = T.val[rt[i]];
			ans += abs(a[j] - b[j]);
		}
	}
	std::cout << ans << "\n";
}