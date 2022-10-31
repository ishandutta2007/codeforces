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

struct FenwickTree {
	typedef int T;
	vector<T> v;
	void init(int n) { v.assign(n, 0); }
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i+1) v[i] += x;
	}
	T sum(int i) const {	//[0, i)
		T r = 0;
		for(-- i; i >= 0; i = (i & (i+1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) const {	//[left, right)
		return sum(right) - sum(left);
	}
};

template<typename It>
void make_fenwick(It beg, size_t n) {
	for(size_t i = 0; i < n; i ++) {
		size_t p = i | (i+1);
		if(p < n) beg[p] += beg[i];
	}
}
template<typename It, typename Val>
void add_fenwick(It beg, size_t n, size_t i, Val val) {
	for(; i < n; i |= i+1) beg[i] += val;
}
template<typename It, typename Val>
Val sum_fenwick(It beg, size_t i, Val sum) {
	for(; i > 0; i = i & (i-1)) sum += beg[i-1];
	return sum;
}
template<typename It>
typename std::iterator_traits<It>::value_type sum_fenwick(It beg, size_t i) {
	return sum_fenwick(beg, i, typename std::iterator_traits<It>::value_type());
}

size_t highestOneBit(size_t v) {
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
#if SIZE_MAX > 0xffffffffULL
	v |= v >> 32;
#endif
	return (v >> 1) + 1;
}

template<typename It, typename Val, typename Cmp>
size_t search_fenwick(It beg, size_t n, Val val, Val left, Cmp cmp) {
	if(!cmp(left, val)) return 0;
	size_t i = 0;
	for(size_t w = highestOneBit(n); w > 0; w >>= 1) {
		if(i + w <= n) {
			Val mid = left;
			mid += beg[i + w - 1];
			if(cmp(mid, val)) {
				i += w;
				left = mid;
			}
		}
	}
	return i + 1;
}
//min ({ i | i <- [0..n], sum(i) >= val } + {n+1})
template<typename It, typename Val>
size_t lower_bound_fenwick(It beg, size_t n, Val val) {
	return search_fenwick(beg, n, val, Val(), std::less<Val>());
}
//min ({ i | i <- [0..n], sum(i) >  val } + {n+1})
template<typename It, typename Val>
size_t upper_bound_fenwick(It beg, size_t n, Val val) {
	return search_fenwick(beg, n, val, Val(), std::less_equal<Val>());
}


vi getord(const vi &p) {
	int n = p.size();
	FenwickTree ft;
	ft.init(n);
	vi v(n);
	for(int i = n-1; i >= 0; -- i) {
		v[i] = ft.sum(p[i]);
		ft.add(p[i], 1);
	}
	return v;
}

vi fromord(const vi &v) {
	int n = v.size();
	vi ft(n, 1);
	make_fenwick(ft.begin(), n);
	vi p(n);
	for(int i = 0; i < n; ++ i) {
		int k = lower_bound_fenwick(ft.begin(), n, v[i] + 1) - 1;
		p[i] = k;
		add_fenwick(ft.begin(), n, k, -1);
	}
	return p;
}

int main() {
	int n;
	scanf("%d", &n);
	vi p(n), q(n);
	rep(i, n) scanf("%d", &p[i]);
	rep(i, n) scanf("%d", &q[i]);
	vi pv = getord(p), qv = getord(q);
//	cerr << "pv = "; each(i, pv) cerr << *i << ", "; cerr << endl;
//	cerr << "qv = "; each(i, qv) cerr << *i << ", "; cerr << endl;
	vi v(n); int carry = 0;
	for(int i = n-1; i >= 0; -- i) {
		int t = pv[i] + qv[i] + carry;
		v[i] = t % (n - i);
		carry = t / (n - i);
	}
//	cerr << "v = "; each(i, v) cerr << *i << ", "; cerr << endl;
	vi r = fromord(v);
	rep(i, n) {
		if(i != 0) putchar(' ');
		printf("%d", r[i]);
	}
	puts("");
	return 0;
}