#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100005;

int n;
ll v[N], t[N];
ll sum = 0, cut = 0;
priority_queue <ll, vector <ll>, greater <ll>> pq;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", v + i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", t + i);
	}
	for (int i = 1; i <= n; ++i) {
		pq.push(v[i] + cut);
		sum += (v[i] + cut);
		// cout << sum << endl;
		ll ans = 0;
		while (!pq.empty() and pq.top() <= cut + t[i]) {
			ans += (pq.top() - cut);
			sum -= pq.top();
			pq.pop();
		}
		cut += t[i];
		ans += ll(pq.size()) * t[i];
		printf("%lld ", ans);
	}
	puts("");
	return 0;
}