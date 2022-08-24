#include<cstdio>
#include<algorithm>
using namespace std;
struct point {
	long long mask, val;
}w[301000];
int n;
int main() {
	int i, j;
	scanf("%d", &n);
	long long s = 0, res = 0;
	for (i = 1; i <= n; i++) {
		scanf("%lld%lld", &w[i].val, &w[i].mask);
		s += w[i].val;
	}
	if (s > 0) {
		for (i = 1; i <= n; i++) w[i].val = -w[i].val;
	}
	for (i = 61; i >= 0; i--) {
		long long s = 0;
		for (j = 1; j <= n; j++) {
			if (w[j].mask == (1ll << i)) {
				s += w[j].val;
			}
		}
		if (s < 0) res += (1ll << i);
		for (j = 1; j <= n; j++) {
			if ((w[j].mask >> i) & 1) {
				w[j].mask ^= (1ll << i);
				if(s<0)w[j].val = -w[j].val;
			}
		}
	}
	printf("%lld\n", res);
}