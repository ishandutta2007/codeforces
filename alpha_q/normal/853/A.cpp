#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int N = 300010;

int n, k, t[N]; ll c[N];
priority_queue <pii> pq;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", c + i);
	}
	for (int i = 1; i <= k; ++i) {
		pq.emplace(c[i], i);
	}
	for (int i = 1, j = k + 1; i <= n; ++i, ++j) {
		if (j <= n) pq.emplace(c[j], j);
		t[pq.top().second] = i + k;
		pq.pop();
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (t[i] - i) * c[i];
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", t[i]);
	}
	puts("");
	return 0;
}