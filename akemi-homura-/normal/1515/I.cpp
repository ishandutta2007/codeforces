#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int LOGN = 18;
const long long INF = 1.1e18;
struct Dat {
	long long a;
	int w, v, id;
} dat[N];
struct Node {
	long long sw[LOGN], sv[LOGN], aw[LOGN], av[LOGN];
} st[N * 4];
int n, q, idx[N];
void Upd(int i, int l, int r, int lf, int rg) {
	if (l == r) {
		for (int j = 1; j < LOGN; j++) {
			if (dat[l].w < (1 << j)) {
				st[i].sw[j] = dat[l].a * dat[l].w;
				st[i].sv[j] = dat[l].a * dat[l].v;
			} else {
				st[i].sw[j] = st[i].sv[j] = 0;
			}
			if (dat[l].w >= (1 << (j - 1)) && dat[l].w < (1 << j) && dat[l].a) {
				st[i].aw[j] = dat[l].w;
				st[i].av[j] = dat[l].v;
			} else {
				st[i].aw[j] = st[i].av[j] = INF;
			}
		}
		return;
	}
	int mid = (l + r) >> 1;
	if (lf <= mid) Upd(i << 1, l, mid, lf, rg);
	if (rg > mid) Upd(i << 1 | 1, mid + 1, r, lf, rg);
	for (int j = 1; j < LOGN; j++) {
		st[i].sw[j] = st[i << 1].sw[j] + st[i << 1 | 1].sw[j];
		st[i].sv[j] = st[i << 1].sv[j] + st[i << 1 | 1].sv[j];
		if (st[i << 1].aw[j] < st[i << 1].sw[j - 1] + st[i << 1 | 1].aw[j]) {
			st[i].aw[j] = st[i << 1].aw[j];
			st[i].av[j] = st[i << 1].av[j];
		} else {
			st[i].aw[j] = st[i << 1].sw[j - 1] + st[i << 1 | 1].aw[j];
			st[i].av[j] = st[i << 1].sv[j - 1] + st[i << 1 | 1].av[j];
		}
	}
}
void query(int i, int l, int r, int j, int &pos, long long &cw, long long &cv) {
	if (pos == l && st[i].sw[j] <= cw) {
		cw -= st[i].sw[j];
		cv += st[i].sv[j];
		pos = r + 1;
		return;
	}
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) query(i << 1, l, mid, j, pos, cw, cv);
	if (pos > mid) query(i << 1 | 1, mid + 1, r, j, pos, cw, cv);
}
int Finda(int i, int l, int r, int j, int &pos, long long &cw) {
	if (pos == l) {
		if (st[i].aw[j] > cw) {
			cw -= st[i].sw[j - 1];
			if (cw >= 0) pos = r + 1;
			return -1;
		} else if (l == r) {
			assert(cw >= st[i].aw[j]);
			return l;
		}
	}
	int mid = (l + r) >> 1, ret = -1;
	if (pos <= mid) ret = Finda(i << 1, l, mid, j, pos, cw);
	if (ret != -1) return ret;
	if (pos > mid) ret = Finda(i << 1 | 1, mid + 1, r, j, pos, cw);
	return ret;
}
int Finda(int j, int pos, long long cw) {
	return Finda(1, 1, n, j, pos, cw);
}
void querysum(int i, int l, int r, int j, int lf, int rg, long long &cw, long long &cv) {
	if (lf <= l && r <= rg) {
		cw -= st[i].sw[j];
		cv += st[i].sv[j];
		return;
	}
	int mid = (l + r) >> 1;
	if (lf <= mid) querysum(i << 1, l, mid, j, lf, rg, cw, cv);
	if (rg > mid) querysum(i << 1 | 1, mid + 1, r, j, lf, rg, cw, cv);
}
long long query(long long c) {
	int pos = 1;
	long long ret = 0;
	for (int i = LOGN - 1; i > 0; i--) {
		query(1, 1, n, i, pos, c, ret);
		if (pos > n) break;
		long long cur = min(dat[pos].a, c / dat[pos].w);
		c -= cur * dat[pos].w;
		ret += cur * dat[pos].v;
		pos++;
		if (pos > n) break;
		int npos = Finda(i, pos, c);
		if (npos != -1) {
			if (pos < npos) querysum(1, 1, n, i - 1, pos, npos - 1, c, ret);
			c -= dat[npos].w;
			ret += dat[npos].v;
			pos = npos + 1;
			if (pos > n) break;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%d%d", &dat[i].a, &dat[i].w, &dat[i].v);
		dat[i].id = i;
	}
	sort(dat + 1, dat + 1 + n, [](Dat x, Dat y) {
		return x.v != y.v ? x.v > y.v : x.w < y.w;
	});
	for (int i = 1; i <= n; i++) idx[dat[i].id] = i;
	Upd(1, 1, n, 1, n);
	while (q--) {
		int ty;
		scanf("%d", &ty);
		if (ty == 1) {
			int k, d;
			scanf("%d%d", &k, &d);
			d = idx[d];
			dat[d].a += k;
			Upd(1, 1, n, d, d);
		} else if (ty == 2) {
			int k, d;
			scanf("%d%d", &k, &d);
			d = idx[d];
			dat[d].a -= k;
			Upd(1, 1, n, d, d);
		} else {
			long long c;
			scanf("%lld", &c);
			printf("%lld\n", query(c));
		}
	}
	return 0;
}