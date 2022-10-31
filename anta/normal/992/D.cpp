#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		vector<pair<int, int> > runs;
		int cnt = 0;
		for (int i = 0; i <= n; i ++) {
			if (i == n || (i != 0 && (as[i] != 1 || as[i] != as[i - 1]))) {
				runs.push_back(make_pair(as[i - 1], cnt));
				cnt = 0;
			}
			cnt ++;
		}
		long long ans = 0;
		for (int i = 0; i != runs.size(); ++ i) {
			long long sum = 0, prod = 1;
			int hL = runs[i].first == 1 ? runs[i].second - 1 : 0;
			for (int j = i + 1; j <= (int)runs.size(); ++ j) {
				int a = runs[j - 1].first;
				int m = runs[j - 1].second;
				int hR = 0;
				if (a == 1) {
					sum += m;
					hR = m - 1;
				} else {
					sum += a;
					if ((double)prod * a > 3e18) break;
					prod *= a;
				}
				//prod / (sum - x) = k
				//x = sum - prod / k
				if (prod % k != 0) continue;
				long long x = sum - prod / k;
				if (x < 0) continue;
				assert(prod == k * (sum - x));
				if (j == i + 1 && a == 1) {
					if (x <= hR) {
						int w = (int)(sum - x);
						long long cnt = m - w + 1;
						ans += cnt;
					}
				} else {
					if (x <= hL + hR) {
						long long cnt = x + 1;
						cnt -= max(0LL, x + 1 - (hL + 1));
						cnt -= max(0LL, x + 1 - (hR + 1));
						cnt += max(0LL, x + 1 - (hL + hR + 2));
						ans += cnt;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
}