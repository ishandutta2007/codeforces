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
#include <complex>
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

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n)
		scanf("%d", &a[i]);
	vector<int> x(n), y(n);
	rep(i, n) {
		x[i] = a[i] == 1;
		y[i] = a[i] == 2;
	}
	make_fenwick(x.begin(), n);
	make_fenwick(y.begin(), n);
	vpii ans;
	rer(s, 1, n) {
		int i = 0, xt = 0, yt = 0, last = -1;
		bool ok = true;
		while(i < n) {
			int xs = sum_fenwick(x.begin(), i);
			int ys = sum_fenwick(y.begin(), i);
			int xj = lower_bound_fenwick(x.begin(), n, xs + s) - 1;
			int yj = lower_bound_fenwick(y.begin(), n, ys + s) - 1;
			if(xj < yj) {
				++ xt;
				last = 1;
				i = xj + 1;
			}else if(yj < xj) {
				++ yt;
				last = 2;
				i = yj + 1;
			}else {
				ok = false;
				break;
			}
		}
		if(last == 1) {
			ok &= xt > yt;
		}else if(last == 2) {
			ok &= yt > xt;
		}
		if(ok)
			ans.pb(mp(max(xt, yt), s));
	}
	sort(all(ans));
	printf("%d\n", (int)ans.size());
	each(i, ans)
		printf("%d %d\n", i->first, i->second);
	return 0;
}