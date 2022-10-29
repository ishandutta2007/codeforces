#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

typedef class Operation {
	public:
		int l, r, mx, tg, t;

		Operation() {	}
		Operation(int l, int r, int mx, int tg, int t) : l(l), r(r), mx(mx), tg(tg), t(t) {	}
} Operation;

#define pii pair<int, int>

const int N = 2e5 + 3;
const int C = 450, CC = 450;

int n, L, q;
pii b[N];
int tg[CC];
int F[CC][CC];
int fr[CC][CC];
int a[N], v[N], c[N];

void save(int tid) {
	int mx = 0, j = 0;
	for (int i = 0, r = 0; i < n; i++) {
		mx = max(v[i] += tg[j], mx);
		if (!r)
			fr[tid][j] = v[i];
		if (++r == C || i == n - 1) {
			F[tid][j] = mx, tg[j] = 0;
			mx = 0, r = 0, j++;
		}
	}
}

vector<Operation> scat[CC];
void modify(int t, int cid, int ql, int qr) {
	int L = cid * C, R = L + C - 1;
	ql = max(L, ql), qr = min(R, qr);
	if (ql == L && qr == R) {
		tg[cid]++;
	} else {
		for (int i = ql; i <= qr; i++)
			v[i]++;
		int mx = 0;
		for (int i = L; i <= R; i++)
			mx = max(mx, v[i] + tg[cid]);
		scat[(t + C - 1) / C].emplace_back(L, R, mx, tg[cid], t);
	}
}

int get_v(int t, int idx) {
	int tid = (t + C - 1) / C, cid = idx / C;
	int pos = cid * C, rt = fr[tid - 1][cid];
	for (int i = (tid - 1) * C + 1; i <= t; i++) {
		if (b[i].second - L + 1 <= pos && b[i].second >= pos) {
			rt++;
		}
	}
	for (int i = pos; i < idx; i++) {
		rt -= c[i] <= t;
		rt += c[i + L] <= t;
	}
	return rt;
}

void work(int l, int r, int x, int& ans) {
	int v = get_v(x, l);
	ans = max(ans, v);
	for (int i = l; i < r; i++)
		ans = max(ans, v += (c[i + L] <= x) - (c[i] <= x));
}

int sc[CC];
int main() {
	scanf("%d%d", &n, &L);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		b[i + 1] = pii(a[i], i);
	}
	sort(b + 1, b + n + 1, greater<pii>());
	for (int i = 1, rest = 0, tid = 0; i <= n; i++) {
		int l = max(0, b[i].second - L + 1), r = b[i].second;
		c[r] = i;
		for (int j = l / C; j <= r / C; j++) {
			modify(i, j, max(0, b[i].second - L + 1), b[i].second);
		}
		if (++rest == C) {
			rest = 0;
			save(++tid);
		}
	}
	scanf("%d", &q);
	int lastans = 0, online = 1, l, r, x, cblock = (n + C - 1) / C;
	while (q--) {
		scanf("%d%d%d", &l, &r, &x);
		--l, --r;
		if (online)
			x ^= lastans;
		x = upper_bound(b + 1, b + n + 1, pii(x, 0), greater<pii>()) - b - 1;
		int lid = l / C, rid = r / C, ans = 0;
		if (x) {
			if (lid == rid || lid + 1 == rid) {
				work(l, r, x, ans);
			} else {
				int tid = (x + C - 1) / C;
				work(l, (lid + 1) * C - 1, x, ans);
				work(rid * C, r, x, ans);
				memset(sc, 0, sizeof(sc));
				for (int t = (tid - 1) * C + 1; t <= x; t++) {
					int ql = max(0, b[t].second - L + 1 + C - 1) / C, qr = (b[t].second + 1) / C;
					if (ql < qr) {
						sc[ql]++;
						sc[qr]--;
					}
				}
				for (int i = 1; i < cblock; i++)
					sc[i] += sc[i - 1];
				for (int i = lid + 1; i < rid; i++)
					ans = max(F[tid - 1][i] + sc[i], ans);
				for (auto& e : scat[tid]) {
					if (e.t > x)
						break;
					if (e.l >= l && e.r <= r) {
						ans = max(e.mx - e.tg + sc[e.l / C], ans);
					}
				}
			}
		}
		lastans = L - ans;
		printf("%d\n", lastans);
	}
	return 0;
}