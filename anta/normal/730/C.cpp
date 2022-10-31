#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

template<typename It>
void make_fenwick(It beg, size_t n) {
	for(size_t i = 0; i < n; i ++) {
		size_t p = i | (i + 1);
		if(p < n) beg[p] += beg[i];
	}
}
template<typename It, typename Val>
void add_fenwick(It beg, size_t n, size_t i, Val val) {
	for(; i < n; i |= i + 1) beg[i] += val;
}
template<typename It, typename Val>
Val sum_fenwick(It beg, size_t i, Val sum) {
	for(; i > 0; i = i & (i - 1)) sum += beg[i - 1];
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

template<typename It, typename Val>
size_t lower_bound_fenwick(It beg, size_t n, Val val) {
	return search_fenwick(beg, n, val, Val(), std::less<Val>());
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<vector<int> > graph(n);
		for(int i = 0; i < m; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int w;
		scanf("%d", &w);
		vector<vpii> shops(n);
		vi prices;
		rep(i, w) {
			int c; int k; int p;
			scanf("%d%d%d", &c, &k, &p), -- c;
			shops[c].emplace_back(k, p);
			prices.push_back(p);
		}
		sort(prices.begin(), prices.end());
		prices.erase(unique(prices.begin(), prices.end()), prices.end());
		int P = (int)prices.size();
		rep(i, n) for(auto &s : shops[i])
			s.second = (int)(lower_bound(prices.begin(), prices.end(), s.second) - prices.begin());
		int q;
		scanf("%d", &q);
		vi que(n), dist, ft;
		vector<ll> ftsum;
		rep(ii, q) {
			int g; int r; int a;
			scanf("%d%d%d", &g, &r, &a), -- g;
			int qt = 0;
			que[qt ++] = g;
			dist.assign(n, INF);
			dist[g] = 0;
			ft.assign(P, 0);
			ftsum.assign(P, 0);
			int ans = -1;
			for(int qh = 0; qh < qt; ++ qh) {
				int i = que[qh];
				int d = dist[i];
				for(auto s : shops[i]) {
					int k, pi;
					tie(k, pi) = s;
					add_fenwick(ft.begin(), ft.size(), pi, k);
					add_fenwick(ftsum.begin(), ftsum.size(), pi, (ll)k * prices[pi]);
				}
				int pi = lower_bound_fenwick(ft.begin(), ft.size(), r) - 1;
				if(pi < P) {
					ll p = sum_fenwick(ftsum.begin(), pi);
					p += (ll)prices[pi] * (r - sum_fenwick(ft.begin(), pi));
					if(p <= a) {
						ans = d;
						break;
					}
				}
				for(int j : graph[i]) {
					if(dist[j] != INF) continue;
					dist[j] = dist[i] + 1;
					que[qt ++] = j;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}