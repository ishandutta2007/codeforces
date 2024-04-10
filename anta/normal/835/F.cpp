#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct Sum {
	ll diam;
	ll eccL, eccR;
	ll length;
	Sum() : diam(0), eccL(0), eccR(0), length(0) {}
	Sum(ll ecc, int len) : diam(ecc), eccL(ecc), eccR(ecc), length(len) {}
	Sum operator+(const Sum &that) const {
		Sum res;
		res.diam = max(max(diam, that.diam), eccR + that.eccL);
		res.eccL = max(eccL, length + that.eccL);
		res.eccR = max(eccR + that.length, that.eccR);
		res.length = length + that.length;
		return res;
	}
};


struct TwoStackQueue {
	using Val = Sum;
	vector<Val> vals1, vals2;
	vector<Sum> sums1, sums2;

	pair<Sum, Sum> getsumparts() const {
		Sum s1 = sums1.empty() ? Sum() : sums1.back();
		Sum s2 = sums2.empty() ? Sum() : sums2.back();
		return make_pair(s2, s1);
	}
	void push(const Val &v) {
		Sum s = !sums1.empty() ? sums1.back() : Sum();
		s = s + v;
		vals1.push_back(v);
		sums1.push_back(s);
	}
	void pop() {
		ensure();
		if (!vals2.empty()) {
			vals2.pop_back();
			sums2.pop_back();
		}
	}

private:
	void ensure() {
		if (!vals2.empty()) return;
		reverse(vals1.begin(), vals1.end());
		vals2.swap(vals1);
		sums1.clear();
		Sum s;
		sums2.resize(vals2.size());
		for (size_t i = 0; i < vals2.size(); ++ i) {
			s = vals2[i] + s;
			sums2[i] = s;
		}
	}
};

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<vector<pair<int, int> > > gw(n);
		for (int i = 0; i < n; ++ i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w), -- u, -- v;
			gw[u].push_back(make_pair(v, w));
			gw[v].push_back(make_pair(u, w));
		}
		vector<int> deg(n);
		vector<int> ord;
		vector<int> parent(n, -1), weight(n, 0);
		rep(i, n) deg[i] = (int)gw[i].size();
		rep(i, n) if (deg[i] == 1)
			ord.push_back(i);
		for (int qh = 0; qh != ord.size(); ++ qh) {
			int i = ord[qh];
			for (auto e : gw[i]) {
				int j = e.first;
				if (deg[j] == 1) continue;
				assert(parent[i] == -1);
				parent[i] = j;
				weight[i] = e.second;
				if ((-- deg[j]) == 1)
					ord.push_back(j);
			}
		}
		vector<pair<int, int>> cycle;
		{
			int root = -1;
			rep(i, n) if(parent[i] == -1) {
				root = i;
				break;
			}
			int i = root, p = -1;
			do {
				for (auto e : gw[i]) if(deg[e.first] == 2 && e.first != p) {
					cycle.emplace_back(i, e.second);
					p = i;
					i = e.first;
					break;
				}
			} while (i != root);
		}
		vector<ll> height(n, 0);
		ll diamBase = 0;
		rep(ix, ord.size()) {
			int i = ord[ix], p = parent[i];
			height[i] += weight[i];
			amax(diamBase, height[p] + height[i]);
			amax(height[p], height[i]);
		}
		int C = (int)cycle.size();
		vector<Sum> seq(C * 2);
		rep(ix, C) {
			ll h = height[cycle[ix].first];
			int len = cycle[ix].second;
			seq[ix * 2 + 0] = Sum(h, 0);
			seq[ix * 2 + 1] = Sum(len, len);
		}
		ll ans = INFL;
		TwoStackQueue tsq;
		rep(i, C * 2 - 1)
			tsq.push(seq[i]);
		rep(k, C) {
			auto parts = tsq.getsumparts();
			Sum sum = parts.first + parts.second;
			ll diam = max(diamBase, sum.diam);
			amin(ans, diam);
			tsq.push(seq[((C + k) * 2 - 1) % (C * 2)]);
			tsq.push(seq[(C + k) * 2 % (C * 2)]);
			rep(l, 2)
				tsq.pop();
		}
		printf("%lld\n", ans);
	}
	return 0;
}