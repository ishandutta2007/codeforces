#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 200015;

struct node1 {
	int l, mid, r;
	pii Max;
	node1 *ls, *rs;

	void pull() {
		Max = max(ls -> Max, rs -> Max);
	}

	void upd(int x, pii v) {
		if (l == r) return Max = v, void();

		(x <= mid ? ls : rs) -> upd(x, v);
		pull();
	}

	pii ask(int x, int y) {
		if (x <= l && r <= y) return Max;

		pii res = mp(-1, -1);

		if (x <= mid) res = max(res, ls -> ask(x, y));

		if (y > mid) res = max(res, rs -> ask(x, y));

		return res;
	}
} P1[N << 2], *ptr1, *rt1;

node1 *build1(int l, int r) {
	// fprintf(stderr, "%d %d\n", l, r);
	node1 *p = ++ptr1;
	int mid = (l + r) >> 1;
	p -> l = l; p -> r = r; p -> mid = mid;
	p -> Max = mp(0, 0);

	if (l != r) {
		p -> ls = build1(l, mid);
		p -> rs = build1(mid + 1, r);
	}

	return p;
}

bool del[N];

struct node2 {
	int l, mid, r;
	vector<pii> S; // (p_j, j)
	node2 *ls, *rs;

	void upd(int x, int y, pii v) {
		if (x <= l && r <= y) {
			S.pb(v);
			return;
		}

		if (x <= mid) ls -> upd(x, y, v);

		if (y > mid) rs -> upd(x, y, v);
	}

	void init() {
		sort(all(S)); reverse(all(S));

		if (l == r) return;

		ls -> init();
		rs -> init();
	}

	pii ask(int x) {
		pii res = mp(inf, inf);

		while (SZ(S) > 0 && del[S.back().se]) {
			S.pop_back();
		}

		if (SZ(S) > 0) res = min(res, S.back());

		if (l != r) {
			res = min(res, (x <= mid ? ls : rs) -> ask(x));
		}

		return res;
	}
} P2[N << 2], *ptr2, *rt2;

node2 *build2(int l, int r) {
	node2 *p = ++ptr2;
	int mid = (l + r) >> 1;
	p -> l = l; p -> r = r; p -> mid = mid;
	p -> S.clear();

	if (l != r) {
		p -> ls = build2(l, mid);
		p -> rs = build2(mid + 1, r);
	}

	return p;
}

void init() {
	ptr1 = P1;
	ptr2 = P2;
}

int s, t, n, p[N], dis[N];

void Del(int x) {
	// fprintf(stderr, "Del %d\n", x);

	del[x] = 1;
	rt1 -> upd(x, mp(-1, -1));
}

void solve() {
	init();
	scanf("%d%d%d", &n, &s, &t);
	rt1 = build1(1, n);
	rt2 = build2(1, n);
	fill(del + 1, del + n + 1, 0);

	rep(i, 1, n) scanf("%d", &p[i]);

	rep(j, 1, n) {
		rt1 -> upd(j, mp(p[j], j));
		rt2 -> upd(max(1, j - p[j]), min(n, j + p[j]), mp(p[j], j));
	}

	rt2 -> init();
	// cerr << "ok";
	queue<int> q;
	q.push(s);
	Del(s); dis[s] = 0;

	while (!q.empty()) {
		int i = q.front();
		q.pop();

		// fprintf(stderr, "(%d %d)\n", i, dis[i]);

		{
			// p_j >= p_i
			int l = max(1, i - p[i]), r = min(n, i + p[i]);

			while (1) {
				// fprintf(stderr, "j [%d %d]\n", l, r);

				auto [pj, j] = rt1 -> ask(l, r);

				if (pj < p[i]) break;

				Del(j); dis[j] = dis[i] + 1;
				q.push(j);
			}
		}

		{
			// p_j < p_i

			while (1) {
				auto [pj, j] = rt2 -> ask(i);

				if (pj >= p[i]) break;

				Del(j); dis[j] = dis[i] + 1;
				q.push(j);
			}
		}
	}

	printf("%d\n", dis[t]);

}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	int T;

	for (scanf("%d", &T); T; T--) solve();

	return 0;
}