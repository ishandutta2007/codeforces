#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

// #pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }

typedef int Ptype;
typedef pair<Ptype, Ptype> Pt;
const Pt Pinf = Pt(numeric_limits<Ptype>::max(), numeric_limits<Ptype>::max());
class RangeTree {
public:
	int n;
	vector<Pt> xsorted;

	vector<vector<Pt>> dat;
	vector<vector<Pii>> bsearch_speedup;
	RangeTree(vector<Pt>& a) {
		n = 1;
		while (n < sz(a)) n <<= 1;
		dat.resize(2 * n - 1);

		//sort by first
		sort(a.begin(), a.end());
		xsorted = a;
		xsorted.resize(n, Pinf);
		bsearch_speedup.resize(n);

		FOR(i, n) {
			int k = n - 1 + i;
			if (i < sz(a)) dat[k].push_back(a[i]);
			else dat[k].push_back(Pinf);
		}
		for (int i = n - 2; i >= 0; i--) {
			auto& cur_dat = dat[i], &lchild = dat[2 * i + 1], rchild = dat[2 * i + 2];
			cur_dat.resize(sz(lchild) + sz(rchild));
			//sort by second
			merge(lchild.begin(), lchild.end(), rchild.begin(), rchild.end(),
				cur_dat.begin(),
				[](const Pt& l, const Pt&  r) { return l.second != r.second ? l.second < r.second : l.first < r.first; }
			);
			//binary_search speed up with fractional cascading
			auto& bs = bsearch_speedup[i];
			bs.resize(sz(cur_dat));
			int a1 = 0, a2 = 0;
			FOR(k, sz(cur_dat)) {
				while (a1 < sz(lchild) && lchild[a1].second < cur_dat[k].second) a1++;
				bs[k].first = a1;
				while (a2 < sz(rchild) && rchild[a2].second < cur_dat[k].second) a2++;
				bs[k].second = a2;
			}
			bs.emplace_back(sz(lchild), sz(rchild));
		}
	}
	// [lx,rx) * [ly,ry) O(log n)
	int query(Ptype lx, Ptype rx, Ptype ly, Ptype ry) {
#define CMP [](const Pt& l, const Ptype val) { return l.second < val; }
		int ly_index = lower_bound(dat[0].begin(), dat[0].end(), ly, CMP) - dat[0].begin();
		int ry_index = lower_bound(dat[0].begin(), dat[0].end(), ry, CMP) - dat[0].begin();
#undef  CMP
		return query(lx, rx, ly_index, ry_index, 0, 0, n);
	}
	int query(Ptype lx, Ptype rx, int ly_index, int ry_index, int k, int a, int b) {
		if (rx <= xsorted[a].first || xsorted[b - 1].first < lx) return 0;
		if (lx <= xsorted[a].first && xsorted[b - 1].first < rx) {
			return ry_index - ly_index;
		}

		int nly_idx_f, nly_idx_s, nry_idx_f, nry_idx_s;
		tie(nly_idx_f, nly_idx_s) = bsearch_speedup[k][ly_index];
		tie(nry_idx_f, nry_idx_s) = bsearch_speedup[k][ry_index];
		int lval = query(lx, rx, nly_idx_f, nry_idx_f, 2 * k + 1, a, (a + b) / 2);
		int rval = query(lx, rx, nly_idx_s, nry_idx_s, 2 * k + 2, (a + b) / 2, b);
		return lval + rval;
	}
};

int near_station(Pii d,RangeTree& rt) {
	int l = -1, r = ten(8) * 4 + 1;
	while (r - l != 1) {
		int md = (r + l) / 2;
		int reach = rt.query(d.first - md, d.first + md + 1, d.second - md, d.second + md + 1);
		if (reach >= 1) r = md;
		else l = md;
	}
	return r;
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	vector<Pii> dwarves(n), stations(k);
	FOR(i, n) {
		int a, b; scanf("%d%d", &a, &b);
		dwarves[i].first = a + b;
		dwarves[i].second = a - b;
	}
	FOR(i, k) {
		int a, b; scanf("%d%d", &a, &b);
		stations[i].first = a + b;
		stations[i].second = a - b;
	}

	RangeTree rt(stations);

	vector<tuple<int, int, int>> dwarves_dist;
	FOR(i, n) {
		int dist = near_station(dwarves[i], rt);
		dwarves_dist.emplace_back(dist, dwarves[i].first, dwarves[i].second);
	}
	sort(dwarves_dist.rbegin(), dwarves_dist.rend());

	int l = -1, r = ten(8) * 2;
	while (r - l != 1) {
		int md = (l + r) / 2;
		int lx = -ten(8) * 2, rx = ten(8) * 2 + 1, ly = -ten(8) * 2, ry = ten(8) * 2 + 1;
		bool b = false;
		FOR(i, n + 1) {
			if (i == n) {
				b = true;
				break;
			}
			int most_far = get<0>(dwarves_dist[i]);
			int s = md - most_far;
			if (s >= 0) {
				int reach = rt.query(lx - s, rx + s + 1, ly - s, ry + s + 1);
				if (reach >= 1) {
					b = true;
					break;
				}
			}

			lx = max(lx, get<1>(dwarves_dist[i]) - md);
			rx = min(rx, get<1>(dwarves_dist[i]) + md);
			ly = max(ly, get<2>(dwarves_dist[i]) - md);
			ry = min(ry, get<2>(dwarves_dist[i]) + md);
			if (lx > rx || ly > ry) break;
		}
		if (b) r = md;
		else l = md;
	}

	cout << r << endl;

	return 0;

}