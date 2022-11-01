#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

priority_queue <long long> pq;
int n, k1, k2;
long long a[N], b[N];

int main() {
	cin >> n >> k1 >> k2;
	k1 += k2;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld", b + i);
		pq.push(abs(a[i] - b[i]));
	}
	while (k1--) {
		long long x = pq.top();
		pq.pop();
		--x;
		pq.push(abs(x));
	}
	long long ans = 0;
	while (!pq.empty()) {
		ans += pq.top() * pq.top();
		pq.pop();
	}
	cout << ans << '\n';
	return 0;
}