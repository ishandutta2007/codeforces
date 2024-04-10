#include <bits/stdc++.h>

const int N = 100005, B = 235241, P = 819657149;

int n, k, q;
int s[N];

int pw[N], inv_pw[N];

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

struct SegmentTree {
	int cnt;

	struct TNode {
		int cl, cr, hl, hr;
		bool can;
		int ls, rs;

		TNode() {
			can = false;
			ls = rs = 0;
		}

		TNode(int v) {
			if (v > 0) {
				cl = 0, cr = 1;
				hl = 0, hr = v;
			} else {
				cl = 1, cr = 0;
				hl = (P + v) % P, hr = 0;
			}
			can = true;
			ls = rs = 0;
		}
	} a[N * 4 + 1005];

	int getLhash(int u, int len) {
		if (a[u].cl == len) {
			return a[u].hl;
		}
		if (len <= a[a[u].ls].cl) {
			return getLhash(a[u].ls, len);
		} else {
			int t = getLhash(a[u].rs, len - a[a[u].ls].cl + a[a[u].ls].cr);
			t = 1ll * (t + a[a[u].ls].hr) * inv_pw[a[a[u].ls].cr] % P;
			t = (1ll * t * pw[a[a[u].ls].cl] + a[a[u].ls].hl) % P;
			return t;
		}
	}

	int getRhash(int u, int len) {
		if (a[u].cr == len) {
			return a[u].hr;
		}
		if (len <= a[a[u].rs].cr) {
			return getRhash(a[u].rs, len);
		} else {
			int t = getRhash(a[u].ls, len - a[a[u].rs].cr + a[a[u].rs].cl);
			t = 1ll * (t + a[a[u].rs].hl) * inv_pw[a[a[u].rs].cl] % P;
			t = (1ll * t * pw[a[a[u].rs].cr] + a[a[u].rs].hr) % P;
			return t;
		}
	}

	void up(int u, int ls, int rs) {
		TNode res;
		res.ls = ls, res.rs = rs;
		res.can = a[ls].can & a[rs].can;
		if (res.can) {
			if (a[ls].cr < a[rs].cl) {
				if ((a[ls].hr + getLhash(rs, a[ls].cr)) % P == 0) {
					res.cl = a[ls].cl + a[rs].cl - a[ls].cr;
					res.cr = a[rs].cr;
					int t = 1ll * (a[rs].hl + a[ls].hr) * inv_pw[a[ls].cr] % P;
					res.hl = (1ll * t * pw[a[ls].cl] + a[ls].hl) % P;
					res.hr = a[rs].hr;
				} else {
					res.can = false;
				}
			} else {
				if ((a[rs].hl + getRhash(ls, a[rs].cl)) % P == 0) {
					res.cl = a[ls].cl;
					res.cr = a[rs].cr + a[ls].cr - a[rs].cl;
					int t = 1ll * (a[ls].hr + a[rs].hl) * inv_pw[a[rs].cl] % P;
					res.hl = a[ls].hl;
					res.hr = (1ll * t * pw[a[rs].cr] + a[rs].hr) % P;
				} else {
					res.can = false;
				}
			}
		}
		a[u] = res;
	}

	void build(int &u, int l, int r) {
		u = ++cnt;
		if (l == r) {
			a[u] = TNode(s[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(a[u].ls, l, mid);
		build(a[u].rs, mid + 1, r);
		up(u, a[u].ls, a[u].rs);
	}

	void modify(int u, int l, int r, int x, int v) {
		if (l == r) {
			a[u] = TNode(v);
			return;
		}
		int mid = (l + r) >> 1;
		if (x <= mid) {
			modify(a[u].ls, l, mid, x, v);
		} else {
			modify(a[u].rs, mid + 1, r, x, v);
		}
		up(u, a[u].ls, a[u].rs);
	}

	int __query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			a[++cnt] = a[u];
			return cnt;
		}
		int mid = (l + r) >> 1;
		if (R <= mid) {
			return __query(a[u].ls, l, mid, L, R);
		} else if (L > mid) {
			return __query(a[u].rs, mid + 1, r, L, R);
		} else {
			int ls = __query(a[u].ls, l, mid, L, R);
			int rs = __query(a[u].rs, mid + 1, r, L, R);
			++cnt;
			up(cnt, ls, rs);
			return cnt;
		}
	}

	bool query(int u, int l, int r, int L, int R) {
		int tmp = cnt;
		int rt = __query(u, l, r, L, R);
		cnt = tmp;
		return a[rt].can && !a[rt].cl && !a[rt].cr;
	}
} T;

int rt;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> s[i];
	}
	int invB = qpow(B, P - 2);
	pw[0] = inv_pw[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw[i] = 1ll * pw[i - 1] * B % P;
		inv_pw[i] = 1ll * inv_pw[i - 1] * invB % P;
	}
	
	T.build(rt, 1, n);
	std::cin >> q;
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int x, v;
			std::cin >> x >> v;
			T.modify(rt, 1, n, x, v);
		} else {
			int l, r;
			std::cin >> l >> r;
			if (T.query(rt, 1, n, l, r)) {
				std::cout << "Yes\n";
			} else {
				std::cout << "No\n";
			}
		}
	}
}