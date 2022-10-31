#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct FenwickTree {
	typedef int T;
	vector<T> v;
	void init(int n) { v.assign(n, T()); }
	void add(int i, T x) {
		for (; i < (int)v.size(); i |= i + 1) v[i] += x;
	}
	T sum(int i) const {	//[0, i)
		T r = T();
		for (-- i; i >= 0; i = (i & (i + 1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) const {	//[left, right)
		return sum(right) - sum(left);
	}
};

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		auto sorted = as;
		sort(sorted.begin(), sorted.end());
		map<int, set<int>> rem;
		rep(i, n)
			rem[as[i]].insert(i);
		FenwickTree ft;
		ft.init(n);
		rep(i, n)
			ft.add(i, 1);
		int pos = 0;
		ll ans = 0;
		for (int x : sorted) {
			auto &S = rem[x];
			auto it = S.lower_bound(pos);
			if (it == S.end())
				it = S.begin();
			int next = *it;
			S.erase(it);
			if (pos <= next) {
				ans += ft.sum(pos, next + 1);
			} else {
				ans += ft.sum(pos, n);
				ans += ft.sum(0, next + 1);
			}
			ft.add(next, -1);
			pos = next;
		}
		printf("%lld\n", ans);
	}
	return 0;
}