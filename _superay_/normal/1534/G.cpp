#include <bits/stdc++.h>
using namespace std;
const int N = 800005;
int n;
pair<int, int> a[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = make_pair(x + y, y);
	}
	sort(a + 1, a + 1 + n);
	priority_queue<int> q1, q2;
	q1.push(0);
	q2.push(0);
	long long bs = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].second <= q1.top()) {
			bs += q1.top() - a[i].second;
			q2.push(a[i].first - q1.top());
			q1.pop();
			q1.push(a[i].second);
			q1.push(a[i].second);
		} else if (a[i].second >= a[i].first - q2.top()) {
			bs += a[i].second - a[i].first + q2.top();
			q1.push(a[i].first - q2.top());
			q2.pop();
			q2.push(a[i].first - a[i].second);
			q2.push(a[i].first - a[i].second);
		} else {
			q1.push(a[i].second);
			q2.push(a[i].first - a[i].second);
		}
	}
	printf("%lld\n", bs);
	return 0;
}