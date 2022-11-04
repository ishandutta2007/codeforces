#include <bits/stdc++.h>
#define M 400010

using namespace std;

typedef long long ll;

int n, m, k;

ll A[M], B[M], ta, tb;

int main() {
	scanf("%d%d%lld%lld%d", &n, &m, &ta, &tb, &k);
	for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= m; i++) scanf("%lld", &B[i]), B[i] -= ta;
	ll ans = 0;
	if(k >= n || k >= m) {
		puts("-1");
		return 0;
	}
	int t = 0;
	for(int i = 0; i <= k; i++) {
		int a = A[i + 1];
		while(t <= m && B[t + 1] < a) t++;
		if(t + 1 + k - i > m) {
			puts("-1");
			return 0;
		} else ans = max(ans, B[t + k - i + 1]);
	}
	printf("%lld\n", ans + ta + tb);
	return 0;
}