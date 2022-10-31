#include "bits/stdc++.h"
using namespace std;

int main() {
	mt19937 re;
	int n; int L;
	while (~scanf("%d%d", &n, &L)) {
		vector<long long> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%lld", &as[i]);
		vector<long long> bs(n);
		for (int i = 0; i < n; ++ i)
			scanf("%lld", &bs[i]);
		sort(as.begin(), as.end());
		sort(bs.begin(), bs.end());
		bs.resize(n * 3);
		for (int i = 0; i < n; ++ i) {
			as[i] += L;
			bs[n + i] = L + bs[i];
			bs[n * 2 + i] = L * 2 + bs[i];
		}
		int lo = 0, up = L / 2;
		while (up - lo > 0) {
			int mid = (lo + up) / 2;
			vector<int> cnt(n + 1);
			for (int i = 0, j = 0, k = 0; i < n; ++ i) {
				for (; j < n * 3 && bs[j] < as[i] - mid; ++ j);
				for (; k < n * 3 && bs[k] <= as[i] + mid; ++ k);

				if (k - j >= n) {
					++ cnt[0], -- cnt[n];
				} else {
					int L = (j - i + n) % n, R = (k - i + n) % n;
					if (L <= R) {
						++ cnt[L], -- cnt[R];
					} else {
						++ cnt[L], -- cnt[n];
						++ cnt[0], -- cnt[R];
					}
				}
			}

			for (int i = 0; i < n; ++ i) cnt[i + 1] += cnt[i];
			bool ok = count(cnt.begin(), cnt.end(), n) != 0;
			if (ok) up = mid; else lo = mid + 1;
		}
		printf("%d\n", up);
	}
}