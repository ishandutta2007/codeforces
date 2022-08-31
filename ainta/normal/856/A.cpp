#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int TC, n, w[110];
int P[11000], cnt, v[1100000];
int main() {
	int i, j;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
		}
		for (i = 1; i <= 1000000; i++)v[i] = 0;
		cnt = 0;
		int r = 0;
		vector<int>Res;
		for (i = 1; i <= n; i++)for (j = 1; j <= n; j++)if (w[i] < w[j])P[cnt++] = w[j] - w[i];
		for (i = 1; i <= 1000000 && r < n; i++) {
			if (!v[i]) {
				r++;
				for (j = 0; j < cnt; j++) {
					if (i + P[j] <= 1000000)v[i + P[j]] = 1;
				}
				Res.push_back(i);
			}
		}
		if (r < n)printf("NO\n");
		else {
			printf("YES\n");
			for (i = 0; i < n; i++)printf("%d ", Res[i]);
			printf("\n");
		}
	}
}