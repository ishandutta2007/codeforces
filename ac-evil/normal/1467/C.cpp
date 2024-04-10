#include <bits/stdc++.h>
using std::min; using std::max;
typedef long long LL;
const int N = 300005;
int n1, n2, n3, m1, m2, m3;
LL s1, s2, s3;
std::vector<int> a;
LL ans = 0;
int main() {
	scanf("%d%d%d", &n1, &n2, &n3);
	m1 = m2 = m3 = 1e9;
	for (int i = 1; i <= n1; i++) {
		int x; scanf("%d", &x);
		m1 = min(m1, x);
		s1 += x;
	}
	for (int i = 1; i <= n2; i++) {
		int x; scanf("%d", &x);
		m2 = min(m2, x);
		s2 += x;
	}
	for (int i = 1; i <= n3; i++) {
		int x; scanf("%d", &x);
		m3 = min(m3, x);
		s3 += x;
	}
	LL s = s1+s2+s3;
	ans = max(ans, s - 2LL*min(min(m1+m2, m1+m3), m2+m3));
	ans = max(ans, max(max(s1+s2-s3, s1+s3-s2), s2+s3-s1));
	printf("%lld", ans);
	return 0;
}