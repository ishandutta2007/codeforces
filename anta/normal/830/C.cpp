#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

void integerDivisionValues(int n, vector<int> &res) {
	res.clear();
	res.push_back(1);
	for (int L = 1, d = n; L <= n; ) {
		int U = n / d;
		res.push_back(U + 1);
		L = U + 1, d = n / L;
	}
}

int main() {
	int n; long long K;
	while (~scanf("%d%lld", &n, &K)) {
		vector<int> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		sort(as.begin(), as.end());
		ll total = accumulate(as.begin(), as.end(), 0LL);
		vector<pair<int, int>> events;
		for (int x : as) {
			int n = x - 1;
			events.emplace_back(1, 0);
			for (int L = 1, d = n; L <= n; ) {
				int U = n / d, pd = d;
				L = U + 1, d = n / L;
				events.emplace_back(U + 1, pd - d);
			}
		}
		sort(events.begin(), events.end());
		ll ans = -1;
		ll sum = total - n;
		rep(bi, events.size()) {
			sum -= events[bi].second;
			int dL = events[bi].first;
			ll dR = bi + 1 == events.size() ? INFL : events[bi + 1].first - 1;
			if (dL > dR) continue;
			ll sum2 = 0;
			for (int x : as)
				sum2 += (x - 1) / dL;
			ll t = (K + total) / (sum + n);
			ll d = min(t, dR);
			if (dL <= d)
				amax(ans, d);
		}
		printf("%lld\n", ans);
	}
	return 0;
}