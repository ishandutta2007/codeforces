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
	int nn;
	scanf("%d", &nn);
	const int C = 100000;
	vector<vi> voters(C);
	int constv = 0;
	rep(i, nn) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a == 0) {
			++ constv;
		}else {
			voters[a-1].push_back(b);
		}
	}
	vector<pair<int,pii> > payall;
	vector<vi> ipayall(C);
	rep(i, C) {
		sort(all(voters[i]));
		int m = voters[i].size();
		ipayall[i].assign(m, -1);
		rep(j, m) {
			payall.push_back(mp(voters[i][j], mp(i, j)));
		}
	}
	sort(all(payall));
	rep(i, payall.size()) {
		pii p = payall[i].second;
		ipayall[p.first][p.second] = i;
	}
	vector<int> ftunused(payall.size(), 0);
	vector<int> ftsum(payall.size(), 0);

	int n = nn - constv;
	vpii cs(C);
	rep(i, C) cs[i] = mp(voters[i].size(), i);
	sort(all(cs));

	vector<int> g(C);

	int ci = 0;
	int ans = INF;
	int total1 = 0;
	rep(c, C) rep(j, voters[c].size()) {
		total1 += voters[c][j];
		++ g[c];
	}
	for(int xx = 0; xx <= n; xx ++) {
		int x = constv + xx;
		if(x == 0) continue;
		//x
		while(ci < (int)cs.size() && cs[ci].first < x) {
			int c = cs[ci].second;
			int t = 0;
			while(t < g[c]) {
				int k = ipayall[c][g[c]-1];
				total1 -= payall[k].first;
				add_fenwick(ftunused.begin(), ftunused.size(), k, 1);
				add_fenwick(ftsum.begin(), ftsum.size(), k, payall[k].first);
				-- g[c];
			}
			++ ci;
		}
		int y = constv;
		reu(i, ci, cs.size()) {
			int c = cs[i].second;
			int t = cs[i].first - x + 1;
			//
			while(t < g[c]) {
				int k = ipayall[c][g[c]-1];
				total1 -= payall[k].first;
				add_fenwick(ftunused.begin(), ftunused.size(), k, 1);
				add_fenwick(ftsum.begin(), ftsum.size(), k, payall[k].first);
				-- g[c];
			}
			y += t;
		}
		int total = total1;
		if(y < x) {
			int bound = lower_bound_fenwick(ftunused.begin(), ftunused.size(), x - y);
			int additional = sum_fenwick(ftsum.begin(), bound);
			total += additional;
		}

		amin(ans, total);
	}
	printf("%d\n", ans);
	return 0;
}