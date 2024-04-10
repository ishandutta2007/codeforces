#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}
int inv(int a, int n) {
	int x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : (x);
}

#define ll long long

typedef class dp_t {
	public:
		int pos;
		ll dis;
		int opt;

		dp_t() {	}
		dp_t(int pos, ll dis, int opt) : pos(pos), dis(dis), opt(opt) {	}

		void upd(ll dist) {
			dis = min(dis, dist);
		}
} dp_t;


int n, m, g;
vector<int> haveL[N], haveR[N];

ll solve(int len, int step, vector<int>& cur, vector<int> opp) {
	ll ret = 0;
	int _step = inv(step % len, len);
	vector<dp_t> F, G;
	for (auto x : cur)
		F.emplace_back(1ll * x * _step % len, x, 0);
	for (auto x : opp)
		F.emplace_back(1ll * x * _step % len, x, 1);
	sort(F.begin(), F.end(), [&] (const dp_t& a, const dp_t& b) {	return a.pos < b.pos;	});
	for (int i = 0, j = 0, sz = F.size(); i < sz; i = j) {
		dp_t cur (-1, 1e18, -1);
		while (j < sz && F[i].pos == F[j].pos) {
			if (F[j].dis < cur.dis) {
				cur = F[j];
			}
			j++;
		}
		G.push_back(cur);
		if (cur.opt)
			ret = max(ret, cur.dis);
	}
	for (int i = 0, sz = G.size(); i < sz; i++)
		G.push_back(G[i]), G.back().pos += len;
	for (int i = 0, sz = G.size(); i < sz - 1; i++)
		G[i + 1].upd(G[i].dis + (G[i + 1].pos - G[i].pos) * 1ll * step);
	for (int i = 0, sz = G.size() >> 1; i < sz; i++)
		G[i].upd(G[i + sz].dis);
	for (int i = 0, sz = G.size() >> 1; i < sz; i++)
		if (G[i].pos + 1 < G[i + 1].pos)
			ret = max(ret, G[i].dis + (G[i + 1].pos - G[i].pos - 1) * 1ll * step);
	return ret;
}

ll solve(int id) {
	vector<int>& Gl = haveL[id];
	vector<int>& Gr = haveR[id];
	if ((signed) Gl.size() == n && (signed) Gr.size() == m)
		return 0;
	ll a = solve(n, m, Gl, Gr);
	ll b = solve(m, n, Gr, Gl);
	return max(a, b) * g + id;
}

int main() {
	int qaq, x;
	scanf("%d%d", &n, &m);
	g = gcd(n, m);
	if (g > 200000) {
		puts("-1");
		return 0;
	}
	scanf("%d", &qaq);
	while (qaq--) {
		scanf("%d", &x);
		haveL[x % g].push_back(x / g);
	}
	scanf("%d", &qaq);
	while (qaq--) {
		scanf("%d", &x);
		haveR[x % g].push_back(x / g);
	}
	for (int i = 0; i < g; i++) {
		if (!(haveL[i].size() + haveR[i].size())) {
			puts("-1");
			return 0;
		}
	}
	ll ans = 0;
	n /= g, m /= g;
	for (int i = 0; i < g; i++) {
		ans = max(ans, solve(i));
	}
	printf("%lld\n", ans);
	return 0;
}