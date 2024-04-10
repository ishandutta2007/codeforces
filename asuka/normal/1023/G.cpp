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
const int N = 100015;

struct node {
	int u, v;
	int dis() const { return v - u; }
};

bool operator < (node x, node y) {return x.dis() > y.dis();}

struct dat {
	map<int, int> pos, neg; int tag;
	priority_queue<node> q;

	void updpos(int x) {
		auto it = neg.upper_bound(x - tag * 2);

		if (it != neg.begin()) q.push((node) {prev(it) -> fi, x});
	}

	void updneg(int x) {
		auto it = pos.lower_bound(x + tag * 2);

		if (it != pos.end()) q.push((node) {x, it -> fi});
	}

	void addpos(int p, int v) {
		pos[p + tag] += v;
		updpos(p + tag);
	}

	void addneg(int p, int v) {
		neg[p - tag] += v;
		updneg(p - tag);
	}

	void inc(int l) {
		while (!q.empty() && q.top().dis() <= (tag + l) * 2) {
			auto [u, v] = mp(q.top().u, q.top().v); q.pop();
			auto iu = neg.find(u), iv = pos.find(v);

			if (iu == neg.end() || iv == pos.end()) continue;

			if (iu -> se + iv -> se > 0) {
				iv -> se += iu -> se;
				neg.erase(iu);
				updpos(v);

			} else {
				iu -> se += iv -> se;
				pos.erase(iv);
				updneg(u);
			}
		}

		tag += l;
	}

	int ask(int p) {
		int res = 0;

		if (pos.find(p + tag) != pos.end()) res += pos[p + tag];

		if (neg.find(p - tag) != neg.end()) res += neg[p - tag];

		return res;
	}

	int size() {return SZ(pos) + SZ(neg);}

	int getres() {
		map<int, int> res;
		int sum = 0, ans = 0;

		for (auto [p, v] : pos) res[p - tag] += v;

		for (auto [p, v] : neg) res[p + tag] += v;

		for (auto [p, v] : res) sum += v, ans = max(ans, sum);

		return ans;
	}
} g[N];

void add(dat &x, dat &y) {
	if (SZ(x) < SZ(y)) swap(x, y);

	for (auto [p, v] : y.pos) x.addpos(p - y.tag, v);

	for (auto [p, v] : y.neg) x.addneg(p + y.tag, v);
}

int n, q;
vector<pii> e[N], fish[N];

void add(int u, int v, int w) {
	e[u].emplace_back(v, w << 1);
	e[v].emplace_back(u, w << 1);
}

void dfs(int u, int pa) {
	for (auto [v, w] : e[u]) {
		if (v == pa) continue;

		dfs(v, u);

		for (auto &[d, f] : fish[v]) f -= max({0, -g[v].ask(d), g[v].ask(d + 1)});

		g[v].inc(1);

		for (auto [d, f] : fish[v]) if (f > 0) g[v].addpos(d, f), g[v].addneg(d + 1, -f);

		g[v].inc(w - 1);
		add(g[u], g[v]);
	}
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);

	rep(i, 2, n) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}

	add(0, 1, 1);
	scanf("%d", &q);

	rep(i, 1, q) {
		int d, f, p; scanf("%d%d%d", &d, &f, &p);
		fish[p].emplace_back(d << 1, f);
	}

	dfs(0, 0);
	printf("%d\n", g[0].getres());
	return 0;
}