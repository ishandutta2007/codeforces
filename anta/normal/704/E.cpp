#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct HLD {
	vector<vi> paths;
	vector<pair<int, int> > pathParent;
	vector<pair<int, int> > nodePos;
	vector<int> nodeDepth;

	void build(const vector<vi> &g, int root) {
		int N = g.size();
		vector<int> t_ord, t_parent(N, -1);
		nodeDepth.assign(N, 0);
		{
			vector<int> stk;
			stk.push_back(root);
			while(!stk.empty()) {
				int i = stk.back();
				stk.pop_back();
				t_ord.push_back(i);
				for(int j : g[i]) if(j != root && t_parent[j] == -1) {
					t_parent[j] = i;
					nodeDepth[j] = nodeDepth[i] + 1;
					stk.push_back(j);
				}
			}
		}
		vector<int> subtsize(N, 1);
		for(int ix = N - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
		}
		paths.clear();
		paths.push_back(vi());
		pathParent.emplace_back(-1, 0);
		dfs(root, -1, g, subtsize);
		assert(paths.back().empty());
		paths.pop_back();
		assert(paths.size() == pathParent.size());

		nodePos.assign(N, { -1, -1 });
		rep(c, paths.size()) rep(p, paths[c].size())
			nodePos[paths[c][p]] = { c, p };
	}

	void get(int u, int &c, int &p) const {
		tie(c, p) = nodePos[u];
	}

	bool go_up(int &c, int &p) const {
		tie(c, p) = pathParent[c];
		return c != -1;
	}

	typedef tuple<int, int, int> SubPath;
	void getEdgeIntervals(int u, int v, vector<SubPath> &path1, vector<SubPath> &path2) const {
		path1.clear();
		path2.clear();
		int uc, up, vc, vp;
		get(u, uc, up);
		get(v, vc, vp);
		while(uc != vc) {
			if(nodeDepth[paths[uc][0]] >= nodeDepth[paths[vc][0]]) {
				path1.emplace_back(uc, -1, up);
				go_up(uc, up);
			} else {
				path2.emplace_back(vc, -1, vp);
				go_up(vc, vp);
			}
		}
		if(up >= vp) {
			path1.emplace_back(uc, vp, up);
		} else {
			path2.emplace_back(vc, up, vp);
		}
		reverse(path2.begin(), path2.end());
	}
private:
	void dfs(int i, int p, const vector<vi> &g, const vector<int> &subtsize) {
		int color = (int)paths.size() - 1;
		int pos = paths.back().size();
		paths.back().push_back(i);

		int c = -1;
		for(int j : g[i]) if(j != p) {
			if(c == -1 || subtsize[c] < subtsize[j])
				c = j;
		}

		if(c == -1) {
			paths.push_back(vi());
			return;
		}

		dfs(c, i, g, subtsize);

		for(int j : g[i]) if(j != p && j != c) {
			pathParent.emplace_back(color, pos);
			dfs(j, i, g, subtsize);
		}
	}
};


struct Ratio32 {
	int num, den;
	Ratio32() : num(0), den(1) {}
	Ratio32(int x, int y) : num(x), den(y) { if(den < 0 || (den == 0 && num < 0)) num = -num, den = -den; }
	bool operator<(const Ratio32 &that) const {
		return (long long)num * that.den < (long long)that.num * den;
	}
	bool operator==(const Ratio32 &that) const {
		return (long long)num * that.den == (long long)that.num * den;
	}
	bool operator<=(const Ratio32 &that) const {
		return !(that < *this);
	}
	bool operator>=(const Ratio32 &that) const {
		return !(*this < that);
	}
	double toDouble() const {
		return (double)num / den;
	}
};

struct Segment {
	static Ratio32 curX;
	int slope;
	int intercept;
	Ratio32 xL, xR;

	Ratio32 getY(const Ratio32 &x) const {
		return Ratio32(slope * x.num + intercept * x.den, x.den);
	}

	bool operator<(const Segment &that) const {
		Ratio32 y0 = getY(curX);
		Ratio32 y1 = that.getY(curX);
		return y0 < y1;
	}

	bool isIntersectTo(const Segment &that, Ratio32 &crossX) const {
		if(slope == that.slope) {
			if(intercept == that.intercept) {
				crossX = max(xL, that.xL);
				return !(xR < that.xL) && !(that.xR < xL);
			} else {
				return false;
			}
		} else {
			int num = intercept - that.intercept;
			int den = that.slope - slope;
			if(den < 0) {
				num = -num;
				den = -den;
			}
			crossX = Ratio32(num, den);
			return
				xL <= crossX && crossX <= xR &&
				that.xL <= crossX && crossX <= that.xR;
		}
	}
};
Ratio32 Segment::curX;

Ratio32 solve(const vector<Segment> &segments) {
	if(segments.empty())
		return Ratio32(INF, 1);
	int n = (int)segments.size();
	vector<pair<Ratio32, int>> events;
	rep(i, n) {
		const Segment &s = segments[i];
		assert(!(s.xR < s.xL));
		events.emplace_back(s.xL, i);
		events.emplace_back(s.xR, n + i);
	}
	sort(events.begin(), events.end());
	multiset<Segment> ss;
	vector<decltype(ss.begin())> iters(n);
	Ratio32 minX(INF, 1);

	auto check = [&minX](const Segment &s, const Segment &t) {
		Ratio32 crossX;
		if(s.isIntersectTo(t, crossX))
			amin(minX, crossX);;
	};

	for(const auto &e : events) {
		if(!(e.first < minX))
			break;
		Segment::curX = e.first;
		if(e.second < n) {
			int i = e.second;
			const Segment &s = segments[i];
			auto lb = ss.lower_bound(s);
			if(lb != ss.end()) {
				check(*lb, s);
			}
			if(lb != ss.begin()) {
				-- lb;
				check(*lb, s);
				++ lb;
			}
			if(!(e.first < minX))
				break;
			iters[i] = ss.insert(lb, segments[i]);
		} else {
			int i = e.second - n;
			auto it = iters[i];
			it = ss.erase(it);
			if(it != ss.end() && it != ss.begin()) {
				const Segment &s = *it;
				-- it;
				check(*it, s);
			}
			iters[i] = {};
		}
	}

	return minX;
}

int main() {
	int n; int m;
	mt19937 re;
	while(~scanf("%d%d", &n, &m)) {
		vector<vector<int> > g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		HLD hld;
		hld.build(g, 0);
		vector<HLD::SubPath> path1, path2;
		vector<vector<Segment>> segments(hld.paths.size());
		rep(i, m) {
			int t; int c; int u; int v;
			scanf("%d%d%d%d", &t, &c, &u, &v), -- u, -- v;
			hld.getEdgeIntervals(u, v, path1, path2);
			int x = t * c;
			for(const HLD::SubPath &p : path1) {
				int col, l, r; tie(col, l, r) = p;
				segments[col].push_back(Segment{ -c, r + x, Ratio32(x, c), Ratio32(x + (r - l), c) });
				x += r - l;
			}
			for(const HLD::SubPath &p : path2) {
				int col, l, r; tie(col, l, r) = p;
				segments[col].push_back(Segment{ +c, l - x, Ratio32(x, c), Ratio32(x + (r - l), c) });
				x += r - l;
			}
		}
		Ratio32 ans(INF, 1);
		rep(c, segments.size()) {
			amin(ans, solve(segments[c]));
		}

		if(ans.num == INF) {
			puts("-1");
		} else {
			printf("%.10f\n", ans.toDouble());
		}
	}
	return 0;
}