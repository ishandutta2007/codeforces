#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


template<typename It>
void make_fenwick(It beg, size_t n) {
	for (size_t i = 0; i < n; i++) {
		size_t p = i | (i + 1);
		if (p < n) beg[p] += beg[i];
	}
}
template<typename It, typename Val>
void add_fenwick(It beg, size_t n, size_t i, Val val) {
	for (; i < n; i |= i + 1) beg[i] += val;
}
template<typename It, typename Val>
Val sum_fenwick(It beg, size_t i, Val sum) {
	for (; i > 0; i = i & (i - 1)) sum += beg[i - 1];
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
	if (!cmp(left, val)) return 0;
	size_t i = 0;
	for (size_t w = highestOneBit(n); w > 0; w >>= 1) {
		if (i + w <= n) {
			Val mid = left;
			mid += beg[i + w - 1];
			if (cmp(mid, val)) {
				i += w;
				left = mid;
			}
		}
	}
	return i + 1;
}

template<typename It, typename Val>
size_t select_fenwick(It beg, size_t n, Val k) {
	return search_fenwick(beg, n, k + 1, Val(), std::less<Val>()) - 1;
}

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> l(n);
		vector<int> r(n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &l[i], &r[i]), ++ r[i];
		vector<int> values = l;
		values.insert(values.end(), r.begin(), r.end());
		sort(values.begin(), values.end());
		values.erase(unique(values.begin(), values.end()), values.end());
		for (vector<int>::iterator it = l.begin(); it != l.end(); ++it)
			*it = lower_bound(values.begin(), values.end(), *it) - values.begin();
		for (vector<int>::iterator it = r.begin(); it != r.end(); ++it)
			*it = lower_bound(values.begin(), values.end(), *it) - values.begin();
		int X = (int)values.size();
		vector<vi> rs(X);
		rep(i, n)
			rs[l[i]].push_back(r[i]);
		vector<int> ft(X, 0);
		int maxNum = 0, maxL = -1;
		rep(L, X) {
			for (int x : rs[L])
				add_fenwick(ft.begin(), ft.size(), X - 1 - x, 1);
			int R = X - 1 - select_fenwick(ft.begin(), ft.size(), k - 1);
			if (L < R) {
				if (maxNum < values[R] - values[L]) {
					maxNum = values[R] - values[L];
					maxL = L;
				}
			}
		}
		vi ans;
		if (maxNum == 0) {
			rep(i, k)
				ans.push_back(i);
		} else {
			vpii list;
			rep(i, n) if (l[i] <= maxL)
				list.emplace_back(r[i], i);
			sort(list.rbegin(), list.rend());
			rep(i, k)
				ans.push_back(list[i].second);
			sort(ans.begin(), ans.end());
		}
		printf("%d\n", maxNum);
		for (int i = 0; i < (int)ans.size(); ++i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}