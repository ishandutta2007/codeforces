#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, deg[N], a[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		long long sum = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), deg[i] = 0, sum += a[i];
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			deg[u]++, deg[v]++;
		}
		vector<int> vec;
		for (int i = 1; i <= n; i++) {
			deg[i]--;
			while (deg[i]--) {
				vec.push_back(a[i]);
			}
		}
		sort(vec.begin(), vec.end(), greater<int>());
		printf("%lld", sum);
		for (int i = 0; i < n - 2; i++) {
			sum += vec[i];
			printf(" %lld", sum);
		}
		puts("");
	}
	return 0;
}