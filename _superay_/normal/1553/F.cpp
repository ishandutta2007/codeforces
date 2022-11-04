#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
struct BIT {
	long long bit[N];
	inline void add(int i, long long x) {
		while (i < N) {
			bit[i] += x;
			i += i & -i;
		}
	}
	inline long long sum(int i) {
		long long ret = 0;
		while (i > 0) {
			ret += bit[i];
			i -= i & -i;
		}
		return ret;
	}
} A, B, C;
int main() {
	int T;
	scanf("%d", &T);
	long long ans = 0;
	for (int i = 0; i < T; i++) {
		int x;
		scanf("%d", &x);
		long long lstb = B.sum(x - 1), curb;
		long long lstc = C.sum(x - 1), curc;
		ans += 1ll * i * x + A.sum(x) + lstb;
		for (int v = x; v < N; v += x) {
			A.add(v, -x);
			curb = B.sum(min(N - 1, v + x - 1));
			curc = C.sum(min(N - 1, v + x - 1));
			ans += curb - lstb - (curc - lstc) * v;
			lstb = curb;
			lstc = curc;
		}
		B.add(x, x);
		C.add(x, 1);
		printf("%lld ", ans);
	}
	return 0;
}