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

//multiset(k+1)
template<typename It, typename Val>
size_t select_fenwick(It beg, size_t n, Val k) {
	return search_fenwick(beg, n, k + 1, Val(), std::less<Val>()) - 1;
}
template<typename It>
size_t next_fenwick(It beg, size_t n, size_t i) {
	typedef typename iterator_traits<It>::value_type Val;
	return search_fenwick(beg, n, sum_fenwick(beg, i) + 1, Val(), std::less<Val>()) - 1;
}

void unionGroup(int x, int y, vector<vi> &groups, vector<int> &teams, vector<bool> &adjmarks, vi &adjacents) {
	x = teams[x], y = teams[y];
	if(x == y) return;
	vi &v = groups[x], &w = groups[y];
	if(v.size() < w.size()) return unionGroup(y, x, groups, teams, adjmarks, adjacents);
	each(i, w) {
		int a = *i;
		assert(teams[a] == y);
		teams[a] = x;
		v.push_back(a);
	}
	each(i, w) {
		int a = *i;
		if(0 < a && adjmarks[a] && teams[a-1] == teams[a]) {
			adjmarks[a] = false;
			add_fenwick(adjacents.begin(), adjacents.size(), a, -1);
		}
		if(a+1 < (int)teams.size() && adjmarks[a+1] && teams[a] == teams[a+1]) {
			adjmarks[a+1] = false;
			add_fenwick(adjacents.begin(), adjacents.size(), a+1, -1);
		}
	}
	w.clear();
}

int main() {
	int n, q;
	while(~scanf("%d%d", &n, &q)) {
		vector<vi> groups(n);
		vector<int> teams(n);
		vector<bool> adjmarks(n+1, true);
		vi adjacents(n+1, 1);
		rep(i, n) {
			groups[i].assign(1, i);
			teams[i] = i;
		}
		make_fenwick(adjacents.begin(), adjacents.size());
		vi v;
		rep(ii, q) {
//			rep(i, n) cerr << teams[i] << ".|"[adjmarks[i+1]]; cerr << endl;
			int ty;
			scanf("%d", &ty);
			if(ty == 1) {
				int x, y;
				scanf("%d%d", &x, &y), -- x, -- y;
				unionGroup(x, y, groups, teams, adjmarks, adjacents);
			}else if(ty == 2) {
				int x, y;
				scanf("%d%d", &x, &y), -- x;
				v.clear();
				int i = x;
				while(i < y) {
					v.push_back(i);
					i = next_fenwick(adjacents.begin(), adjacents.size(), i + 1);
				}
				rep(j, v.size()-1)
					unionGroup(v[j], v[j+1], groups, teams, adjmarks, adjacents);
			}else {
				int x, y;
				scanf("%d%d", &x, &y), -- x, -- y;
				bool ans = teams[x] == teams[y];
				puts(ans ? "YES" : "NO");
			}
		}
	}
	return 0;
}