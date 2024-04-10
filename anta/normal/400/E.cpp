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

namespace vEB_tree {
	static int bsf(unsigned long long x) {
#if defined(__GNUC__)
		return __builtin_ctzll(x);
#else
		int r = 0;
		x &= ~x + 1;
		if(x & 0xffffffff00000000ULL) r += 32;
		if(x & 0xffff0000ffff0000ULL) r += 16;
		if(x & 0xff00ff00ff00ff00ULL) r += 8;
		if(x & 0xf0f0f0f0f0f0f0f0ULL) r += 4;
		if(x & 0xccccccccccccccccULL) r += 2;
		if(x & 0xaaaaaaaaaaaaaaaaULL) r += 1;
		return r;
#endif
	}

	static int bsr(unsigned long long x) {
#if defined(__GNUC__)
		return 63 - __builtin_clzll(x);
#else
		int r = 0;
		if(x & 0xffffffff00000000ULL) x >>= 32, r += 32;
		if(x &         0xffff0000U  ) x >>= 16, r += 16;
		if(x &             0xff00U  ) x >>= 8,  r += 8;
		if(x &               0xf0U  ) x >>= 4,  r += 4;
		if(x &                0xcU  ) x >>= 2,  r += 2;
		if(x &                0x2U  )           r += 1;
		return r;
#endif
	}

	//M = 2^6
	struct NodeLv0 {
		static const int M = 1 << 6;
		unsigned long long bits;

		NodeLv0() { }

		void clear() {
			bits = 0;
		}

		bool empty() const { return bits == 0; }
		int getMin() const { return empty() ?  M : bsf(bits); }
		int getMax() const { return empty() ? -1 : bsr(bits); }

		bool get(int i) const {
			return bits >> i & 1;
		}

		bool insert(int i) {
			bool r = bits == 0;
			bits |= 1ULL << i;
			return r;
		}

		bool remove(int i) {
			unsigned long long mask = 1ULL << i;
			bool r = bits == mask;
			bits &= ~mask;
			return r;
		}

		int findNext(int i) const {
			unsigned long long x = bits >> i;
			if(i >= M || x == 0) return M;
			return i + bsf(x);
		}

		int findPrev(int i) const {
			unsigned long long x = bits << (M - 1 - i);
			if(i < 0 || x == 0) return -1;
			return i - (M - 1 - bsr(x));
		}
	};
	//M = 2^12
	struct NodeLv1 {
		static const int SqrtM = 1 << 6, M = SqrtM * SqrtM;
		short bounds[2];
		NodeLv0 children[SqrtM];
		NodeLv0 summary;

		NodeLv1() { }
		
		void clear() {
			bounds[0] = M;
			bounds[1] = -1;
			for(int i = 0; i < SqrtM; ++ i)
				children[i].clear();
			summary.clear();
		}

		bool empty() const { return bounds[0] == -1; }
		int getMin() const { return bounds[0]; }
		int getMax() const { return bounds[1]; }

		bool get(int i) const {
			return
				bounds[0] == i || bounds[1] == i ||
				children[i / SqrtM].get(i % SqrtM);
		}

		bool insert(int i) {
			int lo = bounds[0], up = bounds[1];
			if(up <= i) {
				if(i == up) return false;
				bounds[1] = i;
				if(up == -1) {
					bounds[0] = i;
					return true;
				}
				if(lo == up)
					return false;
				i = up;
			}else if(i <= lo) {
				if(i == lo) return false;
				bounds[0] = i;
				if(lo == up) 
					return false;
				i = lo;
			}
			int child = i / SqrtM, rem = i % SqrtM;
			if(children[child].insert(rem))
				summary.insert(child);
			return false;
		}

		bool remove(int i) {
			int lo = bounds[0], up = bounds[1];
			if(i <= lo) {
				if(i < lo) return false;
				if(lo == up) {
					bounds[0] = M;
					bounds[1] = -1;
					return true;
				}
				int minChild = summary.getMin();
				if(minChild == SqrtM) {
					bounds[0] = up;
					return false;
				}
				bounds[0] = i = minChild * SqrtM + children[minChild].getMin();
			}else if(up <= i) {
				if(up < i) return false;
				int maxChild = summary.getMax();
				if(maxChild == -1) {
					bounds[1] = lo;
					return false;
				}
				bounds[1] = i = maxChild * SqrtM + children[maxChild].getMax();
			}
			int child = i / SqrtM, rem = i % SqrtM;
			if(children[child].remove(rem))
				summary.remove(child);
			return false;
		}

		int findNext(int i) const {
			if(M <= i) return M;
			int lo = bounds[0];
			if(i <= lo) return lo;
			int child = i / SqrtM, rem = i % SqrtM;
			if(rem <= children[child].getMax()) {
				return child * SqrtM + children[child].findNext(rem);
			}else {
				int nextChild = summary.findNext(child + 1);
				if(nextChild == SqrtM) {
					int hi = bounds[1];
					return i <= hi ? hi : M;
				}
				return nextChild * SqrtM + children[nextChild].getMin();
			}
		}

		int findPrev(int i) const {
			if(i < 0) return -1;
			int hi = bounds[1];
			if(hi <= i) return hi;
			int child = i / SqrtM, rem = i % SqrtM;
			if(children[child].getMin() <= rem) {
				return child * SqrtM + children[child].findPrev(rem);
			}else {
				int prevChild = summary.findPrev(child - 1);
				if(prevChild == -1) {
					int lo = bounds[0];
					return lo <= i ? lo : -1;
				}
				return prevChild * SqrtM + children[prevChild].getMax();
			}
		}
	};
	//M = 2^24
	struct NodeLv2 {
		static const int SqrtM = 1 << 12, M = SqrtM * SqrtM;
		NodeLv1 children[SqrtM];
		NodeLv1 summary;

		NodeLv2() { }

		void clear() {
			for(int i = 0; i < SqrtM; i ++)
				children[i].clear();
			summary.clear();
		}

		bool empty() const { return summary.empty(); }
		int getMin() const { return children[summary.getMin()].getMin(); }
		int getMax() const { return children[summary.getMax()].getMax(); }

		bool get(int i) const {
			return children[i / SqrtM].get(i % SqrtM);
		}

		void insert(int i) {
			int child = i / SqrtM, rem = i % SqrtM;
			if(children[child].insert(rem))
				summary.insert(child);
		}

		void remove(int i) {
			int child = i / SqrtM, rem = i % SqrtM;
			if(children[child].remove(rem))
				summary.remove(child);
		}

		int findNext(int i) const {
			if(M <= i) return M;
			int child = i / SqrtM, rem = i % SqrtM;
			if(rem <= children[child].getMax()) {
				return child * SqrtM + children[child].findNext(rem);
			}else {
				int nextChild = summary.findNext(child + 1);
				if(nextChild == SqrtM)
					return M;
				return nextChild * SqrtM + children[nextChild].getMin();
			}
		}

		int findPrev(int i) const {
			if(i < 0) return -1;
			int child = i / SqrtM, rem = i % SqrtM;
			if(children[child].getMin() <= rem) {
				return child * SqrtM + children[child].findPrev(rem);
			}else {
				int prevChild = summary.findPrev(child - 1);
				if(prevChild == -1)
					return -1;
				return prevChild * SqrtM + children[prevChild].getMax();
			}
		}
	};

	struct VEBTree {
		static const int M = NodeLv2::M;

		NodeLv2 root;

		VEBTree() { clear(); }

		void clear() { root.clear(); }

		bool empty() const { return root.empty(); }
		int getMin() const { return empty() ?  M : root.getMin(); }
		int getMax() const { return empty() ? -1 : root.getMax(); }

		bool get(int i) const { return root.get(i); }

		void insert(int i) { root.insert(i); }
		void remove(int i) { root.remove(i); }

		int findNext(int i) const { return root.findNext(i); }
		int findPrev(int i) const { return root.findPrev(i); }
	};
}


long long calc(int len) {
    return (long long)len * (len+1) / 2;
}
int main() {
	const int B = 17;
    int n, m;
    scanf("%d%d", &n, &m);
	vector<int> a(n);
    rep(i, n) scanf("%d", &a[i]);
	using namespace vEB_tree;
	VEBTree *ts = new VEBTree[B];
	long long ans = 0;
    rep(bit, B) {
		int len = 0;
		long long sum = 0;
		rep(i, n) {
			if(~a[i] >> bit & 1) {
				ts[bit].insert(i);
				len = 0;
			}else {
				sum += ++ len;
			}
		}
		ts[bit].insert(n);
		ans += sum << bit;
    }
	rep(ii, m) {
		int p, v;
		scanf("%d%d", &p, &v), -- p;
		rep(bit, B) if((a[p] ^ v) >> bit & 1) {
			VEBTree &t = ts[bit];

			int bef = t.findPrev(p - 1);
			int aft = t.findNext(p + 1);
			if(v >> bit & 1){
				// 0->1
				ans -= calc(p-bef-1) << bit;
				ans -= calc(aft-p-1) << bit;
				ans += calc(aft-bef-1) << bit;
				t.remove(p);
			}else{
				// 1->0
				ans -= calc(aft-bef-1) << bit;
				ans += calc(p-bef-1) << bit;
				ans += calc(aft-p-1) << bit;
				t.insert(p);
			}
		}
		a[p] = v;
		printf("%I64d\n", ans);
	}
    return 0;
}