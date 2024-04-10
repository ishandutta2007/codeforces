#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		vector<int> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		vector<int> order(n, -1), offset(m + 2);
		for (int i = 0; i < n; ++ i)
			++ offset[as[i] % m + 2];
		for (int x = 0; x <= m; ++ x)
			offset[x + 1] += offset[x];
		for (int i = 0; i < n; ++ i)
			order[offset[as[i] % m + 1] ++] = i;
		offset[0] = 0;
		int d = n / m;
		long long ans = 0;
		for (int k = 0; k < 2; ++ k) {
			for (int x = 0; x < m; ++ x) {
				int c = max(0, offset[x + 1] - offset[x] - d);
				ans += c;
				offset[x + 1] -= c;
			}
			{
				int c = n - offset[m];
				rotate(order.begin(), order.begin() + offset[m], order.end());
				for (int x = 0; x < m; ++ x)
					offset[x + 1] += c;
			}
		}
		vector<int> res(n, -1);
		for (int x = 0; x < m; ++ x) for (int k = 0; k < d; ++ k) {
			int i = order[offset[x] + k];
			res[i] = (as[i] - x + m - 1) / m * m + x;
		}

		printf("%lld\n", ans);
		for (int i = 0; i < (int)res.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", res[i]);
		}
		puts("");
	}
}