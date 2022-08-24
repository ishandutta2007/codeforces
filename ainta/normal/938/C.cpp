#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int TC, n, i;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &n);
		int ck = 0;
		for (i = 1; i*i <= 2000000000; i++) {
			int t = i*i - n;
			if (t < 0)continue;
			int u = (int)(sqrt(1.0*t) + 0.5);
			if (u*u == t && u) {
				int tt = i / u;
				if (i / tt == u) {
					printf("%d %d\n", i, tt);
					ck = 1;
					break;
				}
			}
		}
		if (!ck)printf("-1\n");
	}
}