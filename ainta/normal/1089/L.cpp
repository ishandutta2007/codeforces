#include<cstdio>
#include<algorithm>
using namespace std;
int n, K, pv = 1, C[101000];
long long res;
struct point {
	int x, y;
	bool operator < (const point &p)const {
		return y < p.y;
	}
}w[101000];
int main() {
	int i, j;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i].x);
		C[w[i].x]++;
	}
	for (i = 1; i <= n; i++) scanf("%d", &w[i].y);
	sort(w + 1, w + n + 1);
	int pv = 1;
	for (i = 1; i <= n; i++) {
		if (C[w[i].x] > 1) {
			while (pv <= K && C[pv])pv++;
			if (pv <= K) {
				C[w[i].x]--;
				C[pv]++;
				res += w[i].y;
			}
		}
	}
	printf("%lld\n", res);
}