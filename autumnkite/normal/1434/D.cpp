#include <bits/stdc++.h>

const int N = 500005, L = N << 1, INF = 0x3f3f3f3f;

int n, q;

struct Edge {
	int v, w, id;
};

std::vector<Edge> E[N];
int son[N];

int dep[N], sum[N];
int st[N], ed[N];
int idt[L], idx;

void dfs(int u, int fa) {
	idt[++idx] = u;
	st[u] = idx;
	for (auto e : E[u]) {
		if (e.v != fa) {
			son[e.id] = e.v;
			dep[e.v] = dep[u] + 1;
			sum[e.v] = sum[u] + e.w;
			dfs(e.v, u);
			idt[++idx] = u;
		}
	}
	ed[u] = idx;
}

struct SegmentTree {
	static const int N = ::L << 2;

	int W[N][2], M[N], LM[N][2], MR[N][2], LMR[N][2], tag[N];

	void up(int u) {
		M[u] = std::max(M[u << 1], M[u << 1 | 1]);
		for (int k = 0; k < 2; ++k) {
			W[u][k] = std::max(W[u << 1][k], W[u << 1 | 1][k]);
			LM[u][k] = std::max(LM[u << 1][k], LM[u << 1 | 1][k]);
			LM[u][k] = std::max(LM[u][k], W[u << 1][k] + M[u << 1 | 1]);
			MR[u][k] = std::max(MR[u << 1][k], MR[u << 1 | 1][k]);
			MR[u][k] = std::max(MR[u][k], M[u << 1] + W[u << 1 | 1][k]);
			LMR[u][k] = std::max(LMR[u << 1][k], LMR[u << 1 | 1][k]);
		}
		for (int k1 = 0; k1 < 2; ++k1) {
			for (int k2 = 0; k2 < 2; ++k2) {
				LMR[u][k1 ^ k2] = std::max(LMR[u][k1 ^ k2], 
					std::max(LM[u << 1][k1] + W[u << 1 | 1][k2], W[u << 1][k1] + MR[u << 1 | 1][k2]));
			}
		}
	}

	void rev(int u) {
		std::swap(W[u][0], W[u][1]);
		std::swap(LM[u][0], LM[u][1]);
		std::swap(MR[u][0], MR[u][1]);
		tag[u] ^= 1;
	}

	void down(int u) {
		if (tag[u]) {
			rev(u << 1);
			rev(u << 1 | 1);
			tag[u] = 0;
		}
	}

	void build(int u, int l, int r) {
		if (l == r) {
			int k = sum[idt[l]] & 1;
			W[u][k] = dep[idt[l]];
			M[u] = -2 * dep[idt[l]];
			LM[u][k] = MR[u][k] = -dep[idt[l]];
			W[u][k ^ 1] = -INF;
			LM[u][k ^ 1] = MR[u][k ^ 1] = -INF;
			return;
		}
		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		up(u);
	}

	void modify(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			rev(u);
			return;
		}
		int mid = (l + r) >> 1;
		down(u);
		if (L <= mid) {
			modify(u << 1, l, mid, L, R);
		}
		if(R > mid) {
			modify(u << 1 | 1, mid + 1, r, L, R);
		}
		up(u);
	}
} T;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for(int i = 1; i < n; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		E[u].push_back({v, w, i});
		E[v].push_back({u, w, i});
	}
	dfs(1, 0);
	T.build(1, 1, idx);

	std::cin >> q;
	int dfcmd = 0;
	while (q--) {
		int d;
		std::cin >> d;
		T.modify(1, 1, idx, st[son[d]], ed[son[d]]);
		std::cout << T.LMR[1][0] << std::endl;
		++dfcmd;
	}
}