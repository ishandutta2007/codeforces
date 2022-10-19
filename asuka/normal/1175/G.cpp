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
#pragma pack(0)
using namespace std;

const int N = 20015, K = 105;

int n, k, a[N];

struct line {
	ll k, b;
	ll calc(int x) {return k * x + b;}
};

struct seg {
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define lch ls, l, mid
#define rch rs, mid + 1, r
	line t[N << 2];

	bool vis[N << 2];

	void add(int p, int l, int r, line x, vector<pair<int, line>>& opt) {
		if (!vis[p]) {
			vis[p] = 1;
			opt.emplace_back(p, (line) { -1, -1});
			t[p] = x;
			return;
		}

		if (x.calc(mid) < t[p].calc(mid)) {
			opt.emplace_back(p, t[p]);
			swap(x, t[p]);
		}

		if (l == r) return;

		if (x.k > t[p].k) add(lch, x, opt);
		else add(rch, x, opt);
	}

	ll ask(int p, int l, int r, int pos) {
		if (!vis[p]) return infll;

		ll ans = t[p].calc(pos);

		if (l == r) return ans;

		ans = min(ans, pos <= mid ? ask(lch, pos) : ask(rch, pos));

		return ans;
	}

	void rollback(vector<pair<int, line>>& opt) {
		for (auto [p, y] : opt) {

			if (y.k == -1) vis[p] = 0;
			else t[p] = y;
		}

		vector<pair<int, line>>().swap(opt);
	}
#undef ls
#undef rs
#undef lch
#undef rch
} T;

line t[N << 6];
int tot, ls[N << 6], rs[N << 6];

void init() {
	while (tot) ls[tot] = rs[tot] = 0, tot--;
}

void add(int &p, int l, int r, line x) {
	if (!p) {
		p = ++tot;
		t[p] = x;
		return;
	}

	if (x.calc(mid) < t[p].calc(mid)) swap(x, t[p]);

	if (l == r) return;

	if (x.k > t[p].k) add(ls[p], l, mid, x);
	else add(rs[p], mid + 1, r, x);
}

void merge(int &u, int v, int l, int r) {
	if (!u || !v) return u |= v, void();

	add(u, l, r, t[v]);

	if (l == r) return;

	merge(ls[u], ls[v], l, mid);
	merge(rs[u], rs[v], mid + 1, r);
}

ll ask(int p, int l, int r, int pos) {
	if (!p) return infll;

	ll ans = t[p].calc(pos);

	if (l == r) return ans;

	ans = min(ans, pos <= mid ? ask(ls[p], l, mid, pos) : ask(rs[p], mid + 1, r, pos));

	return ans;
}

#undef mid

struct node {
	int Max, rt;
	vector<pair<int, line>> opt;
	node() {rt = 0;}
};

vector<node*> stk;

ll f[N], nf[N];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	memset(f, 0x3f, sizeof f);
	rep(i, 1, n) scanf("%d", &a[i]);
	int O = *max_element(a + 1, a + n + 1);
	f[0] = 0;

	rep(j, 0, k - 1) {
		init();
		per(i, 0, SZ(stk) - 1) T.rollback(stk[i] -> opt);
		stk.clear();
		rep(i, 1, n) {
			node* u = new node; u -> Max = a[i];

			if (f[i - 1] < infll) add(u -> rt, 1, O, (line) { -i, f[i - 1]});

			while (SZ(stk) > 0 && stk.back() -> Max <= u -> Max) {
				T.rollback(stk.back() -> opt);
				merge(u -> rt, stk.back() -> rt, 1, O);
				stk.pop_back();
			}

			T.add(1, 2, n + 1, (line) {u -> Max, ask(u -> rt, 1, O, u -> Max)}, u -> opt);
			stk.push_back(u);
			nf[i] = T.ask(1, 2, n + 1, i + 1);
		}
		swap(f, nf);
	}
	printf("%lld\n", f[n]);
	return 0;
}