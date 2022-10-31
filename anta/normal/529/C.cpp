#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

typedef int Sum;

struct RangeFenwickTree2D {
	typedef int Pos;
	vector<vector<int> > perms;
	vector<vector<Pos> > poses;
	vector<vector<Sum> > nodes;
	int n, log2n;
	void init(const vector<Pos> &ys, const Sum &v = Sum()) {
		init(ys, vector<Sum>(ys.size(), v));
	}
private:
	struct IndirectPosCmp {
		const vector<int> &ys;
		IndirectPosCmp(const vector<int> &ys_): ys(ys_) { }
		bool operator()(int i, int j) const {
			bool a = i >= (int)ys.size(), b = j >= (int)ys.size();
			if(a || b) return !a < !b;
			else return ys[i] < ys[j];
		}
	};
public:
	void init(const vector<Pos> &ys, const vector<Sum> &vals) {
		n = 1, log2n = 0; while(n < (int)ys.size()) n *= 2, log2n ++;
		nodes.resize(n * 2);

		perms.assign(log2n + 1, vector<int>(n));
		poses.assign(log2n + 1, vector<Pos>(n));
		nodes.assign(log2n + 1, vector<Sum>(n));

		vector<int> prev(n), cnt(n);
		for(int i = 0; i < n; i ++) {
			perms[log2n][i] = i;
			poses[log2n][i] = i < (int)ys.size() ? ys[i] : -1;
			nodes[log2n][i] = i < (int)ys.size() ? vals[i] : Sum();
			cnt[i] = i;
		}

		for(int k = log2n - 1; k >= 0; -- k) {
			prev.swap(cnt);
			int h = 1 << (log2n - k), h2 = (h - 1) / 2 + 1;
			vector<int> &cperms = perms[k];
			vector<int> &cposes = poses[k];
			vector<Sum> &cnodes = nodes[k];
			for(int j = n - h; j >= 0; j -= h) {
				merge(prev.begin() + j, prev.begin() + j + h / 2
					, prev.begin() + j + h / 2, prev.begin() + j + h
					, cnt.begin() + j, IndirectPosCmp(ys));
				for(int i = 0; i < h; i ++) {
					int p = cnt[j + i];
					cperms[p] = j + i;
					cposes[j + i] = p < (int)ys.size() ? ys[p] : -1;
					cnodes[j + i] = p < (int)ys.size() ? vals[p] : Sum();
				}
				for(int i = 0; i < h; i ++) {
					int c = i | (i+1);
					if(c < h) cnodes[j + c] += cnodes[j + i];
				}
			}
		}
	}
	Sum get(int i) const { return nodes[log2n][i]; }
	Sum getRange(int i1, int j1, Pos j2) const {
		Sum res = Sum();
		for(int l = i1 + n, r = j1 + n, k = log2n; l < r; l >>= 1, r >>= 1, -- k) {
			if(l & 1) res += sum(k, l ++, j2);
			if(r & 1) res += sum(k, -- r, j2);
		}
		return res;
	}
	void add(int p, const Sum &x) {
		for(int i = p + n, k = log2n; i > 0; i >>= 1, -- k) {
			int h = 1 << (log2n - k), base = (i - (1 << k)) * h;
			add1(&nodes[k][base], h, perms[k][p] - base, x);
		}
	}
private:
	inline void add1(Sum *cnodes, int h, int i, const Sum &x) const {
		for(; i < h; i |= i+1) cnodes[i] += x;
	}
	inline Sum sum(int k, int i, Pos j2) const {
		if(i >= n) {
			Pos y = poses[k][i - n];
			return y < j2 ? Sum(nodes[k][i - n]) : Sum();
		}else {
			int h = 1 << (log2n - k), base = (i - (1 << k)) * h;
			vector<Pos>::const_iterator it = poses[k].begin() + base;
			int r = lower_bound(it, it + h, j2) - it;
			return getRange1(&nodes[k][base], h, r);
		}
	}
	inline Sum getRange1(const Sum *cnodes, int h, int j) const {
		Sum res = Sum();
		for(-- j; j >= 0; j = (j & (j+1)) - 1) res += cnodes[j];
		return res;
	}
};

int main() {
	int h, w, n, q;
	scanf("%d%d%d%d", &h, &w, &n, &q);
	vpii yxs(n);
	rep(i, n) {
		int y, x;
		scanf("%d%d", &y, &x), -- y, -- x;
		yxs[i] = mp(y, x);
	}
	vector<pair<pair<int,pii>,pii> > queries[2];
	vector<int> heights[2];
	rep(i, q) {
		int y1, x1, y2, x2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2), -- y1, -- x1;
		queries[0].push_back(mp(mp(y1, mp(x1, x2)), mp(i, -1)));
		queries[0].push_back(mp(mp(y2, mp(x1, x2)), mp(i, +1)));
		queries[1].push_back(mp(mp(x1, mp(y1, y2)), mp(i, -1)));
		queries[1].push_back(mp(mp(x2, mp(y1, y2)), mp(i, +1)));
		heights[0].push_back(y2 - y1);
		heights[1].push_back(x2 - x1);
	}
	vector<bool> qans(q, false);
	rep(k, 2) {
		auto &qs = queries[k];
		sort(all(qs));
		sort(all(yxs));

		vpii xis(n);
		rep(i, n) xis[i] = mp(yxs[i].second, i);
		sort(all(xis));

		vector<int> poses(n, -1);
		rep(i, n)
			poses[xis[i].second] = i;

		vector<int> xs(n);
		rep(ix, n) {
			int i = xis[ix].second;
			if(i == 0 || yxs[i-1].first < yxs[i].first) {
				xs[ix] = -1;
			}else {
				xs[ix] = poses[i-1];
			}
		}

		RangeFenwickTree2D rt;
		rt.init(xs, vector<Sum>(n, 0));

		vector<int> ans(q, 0);

		for(int y = 0, ri = 0, qi = 0; y <= h; ++ y) {
			for(; qi < (int)qs.size() && qs[qi].first.first == y; ++ qi) {
				const auto &pp = qs[qi];
				int left, right, i, sign;

				tie(left, right) = pp.first.second;
				tie(i, sign) = pp.second;

				int L = lower_bound(all(xis), mp(left, -1)) - xis.begin();
				int R = upper_bound(all(xis), mp(right, -1)) - xis.begin();
				int sum = rt.getRange(L, R, L);
				ans[i] += sum * sign;
			}
			for(; ri < n && yxs[ri].first == y; ++ ri) {
				int ix = poses[ri];
				rt.add(ix, 1);
			}
		}

		rep(i, q)
			qans[i] = qans[i] || ans[i] == heights[k][i];

		swap(h, w);
		rep(i, n) swap(yxs[i].first, yxs[i].second);
	}

	rep(i, q)
		puts(qans[i] ? "YES" : "NO");
	return 0;
}