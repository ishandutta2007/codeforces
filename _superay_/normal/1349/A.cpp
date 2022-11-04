#include <bits/stdc++.h>
using namespace std;
vector<int> buck[200005];
inline void Gao(int x) {
	for (int i = 2; i * i <= x; i++) if (x % i == 0) {
		int c = 0;
		while (x % i == 0) {
			x /= i;
			c++;
		}
		buck[i].push_back(c);
	}
	if (x > 1) buck[x].push_back(1);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		Gao(x);
	}
	long long ans = 1;
	for (int i = 2; i <= 200000; i++) if ((int)buck[i].size() > n - 2) {
		sort(buck[i].begin(), buck[i].end());
		if ((int)buck[i].size() == n - 1) {
			while (buck[i][0]--) ans *= i;
		} else {
			while (buck[i][1]--) ans *= i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}