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
	typedef ll T;
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
		vector<int> p(n * 2);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &p[i]), -- p[i];
		rep(i, n)
			p[n + i] = p[i];
		FenwickTree ft0, ft1;
		ft0.init(n * 3 + 1);
		ft1.init(n * 3 + 1);
		rep(i, n) {
			ft0.add(p[i] + n * 2 - i, 1);
			ft1.add(p[i] + n * 2 - i, p[i] - i);
		}
		pair<ll, int> ans(INFL, -1);
		rep(shift, n) {
			//|(p_{shift+i} - (shift+i)) + shift|
			ll total = 0;
			int bound = n * 2 - shift;
			ll cnt = ft0.sum(bound);
			ll sum = ft1.sum(bound);
			ll sumR = ft1.sum(bound, n * 3);
			total -= cnt * shift + sum;
			total += (n - cnt) * shift + sumR;
			//cerr << shift << ": " << total << endl;
			amin(ans, make_pair(total, (n - shift) % n));
			{
				int i = shift;
				ft0.add(p[i] + n * 2 - i, -1);
				ft1.add(p[i] + n * 2 - i, -(p[i] - i));
			}
			{
				int i = shift + n;
				ft0.add(p[i] + n * 2 - i, 1);
				ft1.add(p[i] + n * 2 - i, p[i] - i);
			}
		}
		printf("%lld %d\n", ans.first, ans.second);
	}
	return 0;
}