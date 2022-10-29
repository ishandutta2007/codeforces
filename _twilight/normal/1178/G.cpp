#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5, C = 450;

#define ll long long

const ll llf = (signed ll) (~0ull >> 1);

typedef class Chunk {
	public:
		int l, r;
		int ord[C];
		int tg, idx;
		vector<ll> Ks, Bs, Xs;

		Chunk() {	}

		void init(int l, int r);
		void build();
		void append(ll k, ll b);
		void modify(int l, int r, int d);
		void push_down();
		ll query(int l, int r);
} Chunk;

int n, q;
int fa[N];
int a[N], b[N];
int _a[N], _b[N];
vector<int> G[N];
int in[N], out[N];
Chunk ch[N / C + 3];

int dfc;
void dfs(int p) {
	in[p] = ++dfc;
	_a[p] += _a[fa[p]], _b[p] += _b[fa[p]];
	for (auto e : G[p]) {
		dfs(e);
	}
	out[p] = dfc; 
}

ll get_intersect(ll k1, ll b1, ll k2, ll b2) {
	assert(k1 > k2);
	ll dk = k1 - k2, db = b2 - b1;
	// k1 x + b1 >= k2 x + b2
	// (k1 - k2) x >= b2 - b1
	// x >= (b2 - b1) / (k1 - k2)
	return (db < 0) ? (db / dk) : ((db + dk - 1) / dk);
}

void Chunk::append(ll k, ll b) {
	if (!Ks.empty() && Ks.back() == k) {
		if (Bs.back() < b) {
			Ks.pop_back();
			Bs.pop_back();
			Xs.pop_back();
		} else {
			return;
		}
	}
	if (!Ks.size()) {
		Ks.push_back(k);
		Bs.push_back(b);
		Xs.push_back(-llf);
	} else {
		ll x;
		while (!Ks.empty()) {
			x = get_intersect(k, b, Ks.back(), Bs.back());
			if (x <= Xs.back()) {
				Ks.pop_back();
				Bs.pop_back();
				Xs.pop_back();
			} else {
				break;
			}
		}
		x = get_intersect(k, b, Ks.back(), Bs.back());
		Ks.push_back(k);
		Bs.push_back(b);
		Xs.push_back(x);
	}
}

void Chunk::build() {
	Ks.clear(), Bs.clear(), Xs.clear();
	tg = 0, idx = 0;
	for (int i = r - l; ~i; i--)
		append(-b[ord[i]], -1ll * b[ord[i]] * a[ord[i]]);
	for (int i = 0; i <= r - l; i++)
		append(b[ord[i]], 1ll * b[ord[i]] * a[ord[i]]);
	Xs.push_back(llf);
	while (Xs[idx + 1] <= tg)
		idx++;
}

void Chunk::init(int l, int r) {
	this->l = l, this->r = r;
	for (int i = 0; i <= r - l; i++) {
		ord[i] = l + i;
	}
	int len = r - l + 1;
	sort(ord, ord + len, [&] (const int& x, const int& y) {
			return b[x] < b[y];
			});
	build();
}

void Chunk::push_down() {
	if (tg) {
		for (int i = l; i <= r; i++) {
			a[i] += tg;
		}
		tg = 0;
	}
}

void Chunk::modify(int l, int r, int d) {
	if (l == this->l && r == this->r) {
		tg += d;
		while (Xs[idx + 1] <= tg)
			idx++;
	} else {
		push_down();
		for (int i = l; i <= r; i++) {
			a[i] += d;
		}
		build();
	}
} 

ll Chunk::query(int l, int r) {
	if (l == this->l && r == this->r) {
		return Bs[idx] + 1ll * Ks[idx] * tg;
	}
	ll rt = 0;
	for (int i = l; i <= r; i++) {
		rt = max(rt, max(a[i] + tg, -a[i] - tg) * 1ll * b[i]);
	}
	return rt;
}

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++) {
		scanf("%d", fa + i);
		G[fa[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", _a + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", _b + i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (_b[i] < 0)
			_b[i] = -_b[i];
	}
	for (int i = 1; i <= n; i++) {
		a[in[i]] = _a[i];
		b[in[i]] = _b[i];
		//		cerr << i << " " << in[i] << " " << out[i] << " " << a[i] << " " << b[i] << '\n';
	}
	for (int i = 1, r; i <= n; i = r + 1) {
		r = min(n, i + C - 1);
		ch[(i - 1) / C + 1].init(i, r);
	}
	int opt, p, x, l, r, lid, rid;
	while (q--) {
		scanf("%d%d", &opt, &p);
		l = in[p], r = out[p];
		lid = (l - 1) / C + 1, rid = (r - 1) / C + 1;
		if (opt == 1) {
			scanf("%d", &x);
			for (int i = lid; i <= rid; i++) {
				ch[i].modify(max(ch[i].l, l), min(ch[i].r, r), x);
			}
		} else {
			ll ans = 0;
			for (int i = lid; i <= rid; i++) {
				ans = max(ans, ch[i].query(max(ch[i].l, l), min(ch[i].r, r)));
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}