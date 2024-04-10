#define _CRT_SECURE_NO_WARNINGS
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
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }


template<typename InpIt, typename OutIt, typename Val, typename Cmp>
void stackAlgorithm(InpIt it, InpIt end, OutIt out, Cmp cmp = Cmp()) {
	vector<pair<Val,int> > stk;
	for(int i = 0; it != end; ++ i, ++ it) {
		int k = i;
		while(!stk.empty() && cmp(stk.back().first, *it)) {
			k = stk.back().second;
			stk.pop_back();
		}
		*out = k; ++ out;
		stk.push_back(make_pair(*it, k));
	}
}
template<typename InpIt, typename OutIt, typename Cmp>
void stackAlgorithm(InpIt it, InpIt end, OutIt out, Cmp cmp = Cmp()) {
	return stackAlgorithm<InpIt,OutIt,typename iterator_traits<InpIt>::value_type,Cmp>(it, end, out, cmp);
}

typedef int Val;
struct Sum {
	int ma;
	Sum(): ma(-INF) { }
	Sum(Val val): ma(val) { }
	Sum &operator+=(const Sum &that) { amax(ma, that.ma); return *this; }
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};

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
		IndirectPosCmp(const vector<Pos> &ys_): ys(ys_) { }
		bool operator()(int i, int j) const {
			bool a = i >= (int)ys.size(), b = j >= (int)ys.size();
			if(a || b) return !a < !b;
			else return ys[i] < ys[j];
		}
	};
public:
	void init(const vector<Pos> &ys, const vector<Val> &vals) {
		n = 1, log2n = 0; while(n < (int)ys.size()) n *= 2, log2n ++;
		nodes.resize(n * 2);

		perms.assign(log2n + 1, vector<int>(n));
		poses.assign(log2n + 1, vector<Pos>(n));
		leafs.assign(log2n + 1, vector<Val>(n));
		nodes.assign(log2n + 1, vector<Sum>(n));

		vector<int> prev(n), cnt(n);
		for(int i = 0; i < n; i ++) {
			perms[log2n][i] = i;
			poses[log2n][i] = i < (int)ys.size() ? ys[i] : -1;
			leafs[log2n][i] = i < (int)ys.size() ? vals[i] : Val();
			cnt[i] = i;
		}

		for(int k = log2n - 1; k >= 0; -- k) {
			prev.swap(cnt);
			int h = 1 << (log2n - k), h2 = (h - 1) / 2 + 1;
			vector<int> &cperms = perms[k];
			vector<Pos> &cposes = poses[k];
			vector<Val> &cleafs = leafs[k];
			vector<Sum> &cnodes = nodes[k];
			for(int j = n - h; j >= 0; j -= h) {
				merge(prev.begin() + j, prev.begin() + j + h / 2
					, prev.begin() + j + h / 2, prev.begin() + j + h
					, cnt.begin() + j, IndirectPosCmp(ys));
				for(int i = 0; i < h; i ++) {
					int p = cnt[j + i];
					cperms[p] = j + i;
					cposes[j + i] = p < (int)ys.size() ? ys[p] : -1;
					cleafs[j + i] = p < (int)ys.size() ? vals[p] : Val();
				}
				for(int i = h-1; i >= h2; -- i)
					cnodes[j + i] = Sum(cleafs[j + i*2-h]) + Sum(cleafs[j + i*2+1-h]);
				for(int i = h2-1; i > 0; -- i)
					cnodes[j + i] = cnodes[j + i*2] + cnodes[j + i*2+1];
			}
		}
	}
	Val get(int i) const {
		return leafs[log2n][i];
	}
	Sum getRange(int i1, int j1, Pos i2, Pos j2) const {
		Sum res = Sum();
		for(int l = i1 + n, r = j1 + n, k = log2n; l < r; l >>= 1, r >>= 1, -- k) {
			if(l & 1) res += sum(k, l ++, i2, j2);
			if(r & 1) res += sum(k, -- r, i2, j2);
		}
		return res;
	}
	void set(int p, const Val &x) {
		for(int i = p + n, k = log2n; i > 0; i >>= 1, -- k) {
			int h = 1 << (log2n - k), base = (i - (1 << k)) * h;
			set1(&leafs[k][base], &nodes[k][base], h, perms[k][p] - base, x);
		}
	}
private:
	inline void set1(Val *cleafs, Sum *cnodes, int h, int i, const Val &x) const {
		cleafs[i] = x;
		for(i = (i + h) >> 1; i > 0; i >>= 1)
			cnodes[i] = sum1(cleafs, cnodes, h, i*2) + sum1(cleafs, cnodes, h, i*2+1);
	}
	inline Sum sum(int k, int i, Pos i2, Pos j2) const {
		if(i >= n) {
			Pos y = poses[k][i - n];
			return i2 <= y && y < j2 ? Sum(leafs[k][i - n]) : Sum();
		}else {
			int h = 1 << (log2n - k), base = (i - (1 << k)) * h;
			vector<Pos>::const_iterator it = poses[k].begin() + base;
			int l = lower_bound(it, it + h, i2) - it;
			int r = lower_bound(it + l, it + h, j2) - it;
			return getRange1(&leafs[k][base], &nodes[k][base], h, l, r);
		}
	}
	inline Sum getRange1(const Val *cleafs, const Sum *cnodes, int h, int i, int j) const {
		Sum res = Sum();
		for(int l = i + h, r = j + h; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res += sum1(cleafs, cnodes, h, l ++);
			if(r & 1) res += sum1(cleafs, cnodes, h, -- r);
		}
		return res;
	}
	inline Sum sum1(const Val *cleafs, const Sum *cnodes, int h, int i) const {
		return i >= h ? Sum(cleafs[i - h]) : cnodes[i];
	}
};


int main() {
	int N;
	scanf("%d", &N);
	vector<int> h(N);
	rep(i, N) {
		scanf("%d", &h[i]);
//		h[i]=rand()%5+1;
//		cerr << h[i]<<" ";
	}
//	cerr<<endl;
	vector<int> L(N), R(N);
	stackAlgorithm(h.begin(), h.end(), L.begin(), greater_equal<int>());
	stackAlgorithm(h.rbegin(), h.rend(), R.rbegin(), greater_equal<int>());
	rep(i, N) R[i] = N - 1 - R[i];
	vector<pair<pii,int> > pointsLR(N+1), pointsRL(N);
	rep(i, N) {
		int l = L[i], r = R[i];
		pointsLR[i] = mp(mp(l, r), i);
		pointsRL[i] = mp(mp(r, l), i);
	}
	pointsLR[N] = mp(mp(INF, INF), -INF);
	sort(all(pointsLR));
	sort(all(pointsRL));
	vector<int> rIndices(N);
	rep(i, N)
		rIndices[pointsRL[i].second] = i;
	int M;
	scanf("%d", &M);
	vector<pair<pii,pii> > queries(M);
	rep(i, M) {
		int l, r, w;
		scanf("%d%d%d", &l, &r, &w), -- l, -- r;
//		l=rand()%N,r=rand()%N;if(l>r)swap(l,r);w=rand()%(r-l+1)+1;
//		cerr<<l<<" "<<r<<" "<<w<<endl;
		//min(pr,qr) - max(pl,ql) >= w - 1
		//1. prqr, plql: pr >= ql + w - 1
		//2. prqr, plql: pr - pl >= w - 1
		//3. prqr, plql: True
		//4. prqr, plql: pl <= qr - w + 1
		queries[i] = mp(mp(l, r), mp(w, i));
		/*
		int naiveans = 0;
		rer(j, l, r+1-w) {
			int a = INF;
			rep(k, w)
				amin(a, h[j+k]);
			amax(naiveans,a);
		}
		cerr << "naiveans: " << naiveans << endl;
		*/
	}
	sort(all(queries));
	vector<int> ysL(N), ysRL(N), ysR(N);
	rep(i, N) {
		int l = pointsRL[i].first.second, r = pointsRL[i].first.first;
		ysL[i] = l;
		ysRL[i] = r - l;
		ysR[i] = r;
	}
	vector<int> inithhs(N);
	rep(i, N)
		inithhs[i] = h[pointsRL[i].second];
	GetRangeRangeTree2D rt1, rt2, rt3, rt4;
	rt1.init(ysR);
	rt2.init(ysRL, inithhs);
	rt3.init(vector<int>(N, 0));
	rt4.init(ysL, inithhs);
	vector<int> ans(M, -1);
	int qi = 0;
	for(int pi = 0; ; ++ pi) {
		int L = pointsLR[pi].first.first;
		while(qi < M && queries[qi].first.first < L) {
			int ql = queries[qi].first.first, qr = queries[qi].first.second;
			int w = queries[qi].second.first, i = queries[qi].second.second;
			//plql
			int ri = upper_bound(all(pointsRL), mp(mp(qr,INF), INF)) - pointsRL.begin();
			//ixri <-> prqr
			Sum sum = 0;
			sum += rt1.getRange(0, ri, ql + w - 1, INF);
			sum += rt2.getRange(0, ri, w - 1, INF);
			sum += rt3.getRange(ri, N, 0, INF);
			sum += rt4.getRange(ri, N, -INF, (qr - w + 1) + 1);
			ans[i] = sum.ma;
			++ qi;
		}
		if(pi == N) break;
		int j = pointsLR[pi].second, idx = rIndices[j], hh = h[j];
		rt1.set(idx, hh);   //cout << "+rt1 " << pointsLR[pi].first.second << ", " << ysR[idx] << ": " << hh << endl;
		rt2.set(idx, -INF); //cout << "-rt2 " << pointsLR[pi].first.second << ", " << ysRL[idx] << ": " << hh << endl;
		rt3.set(idx, hh);   //cout << "+rt3 " << pointsLR[pi].first.second << ", " << 0 << ": " << hh << endl;
		rt4.set(idx, -INF); //cout << "-rt4 " << pointsLR[pi].first.second << ", " << ysL[idx] << ": " << hh << endl;
	}
	rep(i, M)
		printf("%d\n", ans[i]);
	return 0;
}