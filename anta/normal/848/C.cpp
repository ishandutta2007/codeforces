#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

using Val = int;
using Sum = ll;

struct GetRangeRangeTree2D {
	typedef int Pos;
	vector<vector<int> > perms;
	vector<vector<Pos> > poses;
	vector<vector<Val> > leafs;
	vector<vector<Sum> > nodes;
	int n, log2n;
	void init(const vector<Pos> &ys, const Val &v = Val()) {
		init(ys, vector<Val>(ys.size(), v));
	}
private:
	struct IndirectPosCmp {
		const vector<Pos> &ys;
		IndirectPosCmp(const vector<Pos> &ys_) : ys(ys_) { }
		bool operator()(int i, int j) const {
			bool a = i >= (int)ys.size(), b = j >= (int)ys.size();
			if (a || b) return !a < !b;
			else return ys[i] < ys[j];
		}
	};
public:
	void init(const vector<Pos> &ys, const vector<Val> &vals) {
		n = 1, log2n = 0; while (n < (int)ys.size()) n *= 2, log2n ++;
		nodes.resize(n * 2);

		perms.assign(log2n + 1, vector<int>(n));
		poses.assign(log2n + 1, vector<Pos>(n));
		leafs.assign(log2n + 1, vector<Val>(n));
		nodes.assign(log2n + 1, vector<Sum>(n));

		vector<int> prev(n), cnt(n);
		for (int i = 0; i < n; i ++) {
			perms[log2n][i] = i;
			poses[log2n][i] = i < (int)ys.size() ? ys[i] : -1;
			leafs[log2n][i] = i < (int)ys.size() ? vals[i] : Val();
			cnt[i] = i;
		}

		for (int k = log2n - 1; k >= 0; -- k) {
			prev.swap(cnt);
			int h = 1 << (log2n - k), h2 = (h - 1) / 2 + 1;
			vector<int> &cperms = perms[k];
			vector<Pos> &cposes = poses[k];
			vector<Val> &cleafs = leafs[k];
			vector<Sum> &cnodes = nodes[k];
			for (int j = n - h; j >= 0; j -= h) {
				merge(prev.begin() + j, prev.begin() + j + h / 2
					, prev.begin() + j + h / 2, prev.begin() + j + h
					, cnt.begin() + j, IndirectPosCmp(ys));
				for (int i = 0; i < h; i ++) {
					int p = cnt[j + i];
					cperms[p] = j + i;
					cposes[j + i] = p < (int)ys.size() ? ys[p] : -1;
					cleafs[j + i] = p < (int)ys.size() ? vals[p] : Val();
				}
				for (int i = h - 1; i >= h2; -- i)
					cnodes[j + i] = Sum(cleafs[j + i * 2 - h]) + Sum(cleafs[j + i * 2 + 1 - h]);
				for (int i = h2 - 1; i > 0; -- i)
					cnodes[j + i] = cnodes[j + i * 2] + cnodes[j + i * 2 + 1];
			}
		}
	}
	Val get(int i) const {
		return leafs[log2n][i];
	}
	Sum getRange(int i1, int j1, Pos i2, Pos j2) const {
		Sum res = Sum();
		for (int l = i1 + n, r = j1 + n, k = log2n; l < r; l >>= 1, r >>= 1, -- k) {
			if (l & 1) res += sum(k, l ++, i2, j2);
			if (r & 1) res += sum(k, -- r, i2, j2);
		}
		return res;
	}
	void set(int p, const Val &x) {
		for (int i = p + n, k = log2n; i > 0; i >>= 1, -- k) {
			int h = 1 << (log2n - k), base = (i - (1 << k)) * h;
			set1(&leafs[k][base], &nodes[k][base], h, perms[k][p] - base, x);
		}
	}
private:
	inline void set1(Val *cleafs, Sum *cnodes, int h, int i, const Val &x) const {
		cleafs[i] = x;
		for (i = (i + h) >> 1; i > 0; i >>= 1)
			cnodes[i] = sum1(cleafs, cnodes, h, i * 2) + sum1(cleafs, cnodes, h, i * 2 + 1);
	}
	inline Sum sum(int k, int i, Pos i2, Pos j2) const {
		if (i >= n) {
			Pos y = poses[k][i - n];
			return i2 <= y && y < j2 ? Sum(leafs[k][i - n]) : Sum();
		} else {
			int h = 1 << (log2n - k), base = (i - (1 << k)) * h;
			vector<Pos>::const_iterator it = poses[k].begin() + base;
			int l = lower_bound(it, it + h, i2) - it;
			int r = lower_bound(it + l, it + h, j2) - it;
			return getRange1(&leafs[k][base], &nodes[k][base], h, l, r);
		}
	}
	inline Sum getRange1(const Val *cleafs, const Sum *cnodes, int h, int i, int j) const {
		Sum res = Sum();
		for (int l = i + h, r = j + h; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res += sum1(cleafs, cnodes, h, l ++);
			if (r & 1) res += sum1(cleafs, cnodes, h, -- r);
		}
		return res;
	}
	inline Sum sum1(const Val *cleafs, const Sum *cnodes, int h, int i) const {
		return i >= h ? Sum(cleafs[i - h]) : cnodes[i];
	}
};

struct Query {
	int ty;
	int l, r;
	pair<int, int> val;
};

int main() {
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		vector<pair<int,pii>> values;
		int A = n + 1;
		vector<set<int>> curPoses(A);
		vector<pair<int,int>> curSeq(n);
		vector<Query> queries;
		for (int i = 0; i < n; ++ i) {
			int a;
			scanf("%d", &a);
			int lastpos = curPoses[a].empty() ? -1 : *curPoses[a].rbegin();
			curSeq[i] = make_pair(a, lastpos);
			values.emplace_back(i, curSeq[i]);
			curPoses[a].insert(i);
			queries.push_back(Query{ 1, i, i, curSeq[i] });
		}
		for (int ii = 0; ii < m; ++ ii) {
			int ty;
			scanf("%d", &ty);
			if (ty == 1) {
				int p; int x;
				scanf("%d%d", &p, &x), -- p;
				if (curSeq[p].first == x) continue;
				auto remove = [&queries, &curSeq](int i) {
					queries.push_back(Query{ 0, i, i, curSeq[i] });
				};
				auto insert = [&queries, &curSeq, &curPoses, &values](int i, int x) {
					auto it = curPoses[x].lower_bound(i);
					int lastpos = it == curPoses[x].begin() ? -1 : *(-- it);
					curPoses[x].insert(i);
					curSeq[i] = make_pair(x, lastpos);
					values.emplace_back(i, curSeq[i]);
					queries.push_back(Query{ 1, i, i, curSeq[i] });
				};
				{
					int y = curSeq[p].first;
					remove(p);
					curPoses[y].erase(p);
					auto it = curPoses[y].upper_bound(p);
					if (it != curPoses[y].end()) {
						int j = *it;
						remove(j);
						insert(j, y);
					}
				}
				{
					insert(p, x);
					auto it = curPoses[x].upper_bound(p);
					if (it != curPoses[x].end()) {
						int j = *it;
						remove(j);
						insert(j, x);
					}
				}
			} else if (ty == 2) {
				int l; int r;
				scanf("%d%d", &l, &r), -- l;
				queries.push_back(Query{ 2, l, r, make_pair(-1, -1) });
			} else abort();
		}
		sort(values.begin(), values.end());
		vector<int> ys;
		for (auto x : values)
			ys.push_back(x.second.second);
		GetRangeRangeTree2D segt;
		segt.init(ys, vector<int>(values.size(), 0));
		int kk = 0;
		for(auto q : queries) {
			if (q.ty == 0 || q.ty == 1) {
				auto val = make_pair(q.l, q.val);
				int ix = (int)(lower_bound(values.begin(), values.end(), val) - values.begin());
				assert(ix != values.size() && values[ix] == val);
				int coeff = q.ty == 0 ? 0 : q.l - q.val.second;
				segt.set(ix, coeff);
			} else if (q.ty == 2) {
				int L = (int)(lower_bound(values.begin(), values.end(), make_pair(q.l, make_pair(0, 0))) - values.begin());
				int R = (int)(lower_bound(values.begin(), values.end(), make_pair(q.r, make_pair(0, 0))) - values.begin());
				ll ans = segt.getRange(L, R, q.l, INF);
				printf("%lld\n", ans);
			} else abort();
		}
	}
	return 0;
}