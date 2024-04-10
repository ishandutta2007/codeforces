#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct DynamicRMQ {
	typedef ll Val;
	int n;
	vector<Val> d;
	void init(int nmin) {
		for (n = 1; n < nmin; n *= 2);
		d.assign(n * 2, -INFL);
	}
	void update(int i, Val x) {
		d[n + i] = x;
		for (int k = (n + i) / 2; k > 0; k >>= 1)
			d[k] = max(d[k * 2], d[k * 2 + 1]);
	}
	Val get(int i) const { return d[n + i]; }
	//[l, r)
	Val query(int l, int r) const {
		Val m = -INFL;
		for (; l && l + (l&-l) <= r; l += l&-l)
			m = max(m, d[(n + l) / (l&-l)]);
		for (; l < r; r -= r&-r)
			m = max(m, d[(n + r) / (r&-r) - 1]);
		return m;
	}
};

int main() {
	int N; long long C;
	while (~scanf("%d%lld", &N, &C)) {
		vector<int> A(N * 2 - 1);
		for (int i = 0; i < N * 2 - 1; ++ i)
			scanf("%d", &A[i]);
		vector<ll> psum(A.size() + 1);
		rep(i, A.size())
			psum[i + 1] = psum[i] + A[i];
		DynamicRMQ rmq0, rmq1;
		rmq0.init(N + 1);
		rmq1.init(N + 1);
		rmq0.update(0, 0);
		rmq1.update(0, 0);
		int curL = 0;
		rep(R, N * 2 - 1) {
			for (; psum[R + 1] - psum[curL] > C; ++ curL);
			ll x = 0;
			if (0 < curL) {
				ll t = rmq0.query(0, (curL - 1) / 2 + 1);
				amax(x, t + C);
			}
			if (curL <= R) {
				int bL = curL / 2 + 1, bR = R / 2 - 1;
				ll t = -INFL;
				if(bL <= bR)
					amax(t, rmq1.query(bL, bR + 1));
				reu(L, curL, bL * 2) if (curL <= L && L <= R)
					amax(t, rmq0.get(L / 2) - psum[L]);
				rer(L, bR * 2, R) if (curL <= L && L <= R)
					amax(t, rmq0.get(L / 2) - psum[L]);
				amax(x, t + psum[R + 1]);
			}
			int i = (R + 1) / 2 + 1;
			rmq0.update(i, max(rmq0.get(i), x));
			rer(L, max(0, R - 2), R + 2)
				rmq1.update(L / 2, max(rmq1.get(L / 2), rmq0.get(L / 2) - psum[L]));
		}
		ll ans = rmq0.get(N);
		printf("%lld\n", ans);
	}
	return 0;
}