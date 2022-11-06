#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const long double INF = 1e60;

struct Line {
	ll a, b;
	mutable long double xl = -INF;  // x-coord of intersection with previous line in set
	int i;
};

struct StaticHull {
	vector<Line> lines;
	vector<Line>::iterator it;

	StaticHull() {
	}
	StaticHull(const vector<Line> &v) { // sorted by a
		for (int i = 0; i + 1 < (int) v.size(); ++i)
			assert(v[i].a <= v[i + 1].a);

		for (const Line &line : v) {
			if (!lines.empty() && lines.back().a == line.a) {
				if (lines.back().b >= line.b)
					continue;
				lines.pop_back();
			}
			while (lines.size() >= 2) {
				const Line &x = *(lines.end() - 2);
				const Line &y = *(lines.end() - 1);
				const Line &z = line;
				const bool bad = 1.0L * (x.b - y.b) * (z.a - y.a) >= 1.0L * (y.b - z.b) * (y.a - x.a);
				if (!bad)
					break;
				lines.pop_back();
			}
			if (lines.empty())
				line.xl = -INF;
			else {
				const Line &x = *(lines.end() - 1);
				const Line &y = line;
				y.xl = 1.0L * (y.b - x.b) / (x.a - y.a);
				assert(x.xl < y.xl);
			}
			lines.push_back(line);
		}

		it = lines.begin();
	}

	ll eval(const ll x) { // find max ax+b, over all lines added, for given x
		assert(!lines.empty());

		// OPTION 1:
		/*static auto comp = [](const Line &line1, const Line &line2) {
		 return line1.xl < line2.xl;
		 };
		 Line line;
		 line.xl = x;
		 auto it = lower_bound(lines.begin(), lines.end(), line, comp);
		 */

		// OPTION 2:
		while (it != lines.end() && it->xl < x)
			++it;

		assert(it != lines.begin());
		--it;
		assert(it->xl < x);
		return it->a * x + it->b;
	}
};

const int MxN = (int) 2e5 + 9;
vector<int> adj[MxN + 9];
int parent[MxN + 9];
int startT[MxN + 9];
int finT[MxN + 9];
ll a[MxN + 9];
ll b[MxN + 9];

void dfs(const int u, int &t) {
	startT[u] = t++;
	for (int v : adj[u])
		dfs(v, t);
	finT[u] = t - 1;
}

struct Comp {
	vector<Line> lines;
	StaticHull hull;
	ll lazy = 0;
	void init(const int first, const int last) {
		assert(lines.empty());
		for (int i = first; i < last; ++i)
			for (const int coeff : { -1, 1 }) {
				Line line;
				line.a = b[i] * coeff;
				line.b = a[i] * line.a;
				line.i = i;
				lines.push_back(line);
			}
		sort(lines.begin(), lines.end(), [](const Line &line1, const Line &line2) {
			return line1.a < line2.a;
		});
		hull = StaticHull(lines);
	}

	void add(const int l, const int r, const ll x) {
		for (Line &line : lines)
			if (l <= line.i && line.i <= r)
				line.b += x * line.a;
		hull = StaticHull(lines);
	}

	void addAll(const ll x) {
		lazy += x;
	}
	ll queryAll() {
		return hull.eval(lazy);
	}
	ll query(const int l, const int r) const {
		ll res = numeric_limits<ll>::min();
		for (const Line &line : lines)
			if (l <= line.i && line.i <= r)
				res = max(res, line.b + lazy * line.a);
		return res;
	}

};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, Q;
	cin >> n >> Q;
	for (int i = 2; i <= n; ++i) {
		cin >> parent[i];
		adj[parent[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	for (int i = 2; i <= n; ++i) {
		a[i] += a[parent[i]];
		b[i] += b[parent[i]];
	}
	for (int i = 1; i <= n; ++i)
		b[i] = llabs(b[i]);

	{
		int t = 0;
		dfs(1, t);
		assert(t == n);
	}

	{ // permute a and b
		vector<ll> A(a, a + 1 + n);
		vector<ll> B(b, b + 1 + n);
		for (int i = 1; i <= n; ++i) {
			a[startT[i]] = A[i];
			b[startT[i]] = B[i];
		}
		a[n] = b[n] = 0;
	}

	const int sz = max(1, (int) sqrt(n + .5) / 4);
	vector<Comp> comps((n + sz - 1) / sz);
	for (int i = 0; i * sz < n; ++i)
		comps[i].init(i * sz, min(n, (i + 1) * sz));

	while (Q--) {
		int type, _u;
		cin >> type >> _u;
		const int l = startT[_u];
		const int r = finT[_u];
		const int L = l / sz;
		const int R = r / sz;

		if (type == 1) {
			ll x;
			cin >> x;
			comps[L].add(l, r, x);
			if (L < R) {
				comps[R].add(l, r, x);
				for (int I = L + 1; I < R; ++I)
					comps[I].addAll(x);
			}
		} else {
			assert(type == 2);
			ll res = comps[L].query(l, r);
			if (L < R) {
				res = max(res, comps[R].query(l, r));
				for (int I = L + 1; I < R; ++I)
					res = max(res, comps[I].queryAll());
			}
			cout << res << '\n';
		}
	}
	return 0;
}