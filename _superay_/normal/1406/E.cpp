#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int zhi[N], pri[N], tot;
inline void Init(int n = 100000) {
	zhi[1] = 1;
	tot = 0;
	for (int i = 2; i <= n; i++) {
		if (!zhi[i]) pri[++tot] = i;
		for (int j = 1; j <= tot && i * pri[j] <= n; j++) {
			zhi[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
}
int n, sq;
int main() {
	Init();
	scanf("%d", &n);
	for (sq = 1; sq * sq <= n; sq++); sq--;
	vector<int> vec;
	for (int i = 1; i <= tot && pri[i] <= sq; i++) {
		vec.push_back(pri[i]);
	}
	for (int p : vec) {
		printf("B %d\n", p);
		fflush(stdout);
		scanf("%*d");
	}
	int prd = 1;
	for (int p : vec) {
		printf("A %d\n", p);
		fflush(stdout);
		int t;
		scanf("%d", &t);
		if (t) {
			int e = 1, pw = p;
			while (true) {
				e++;
				pw *= p;
				if (pw > n) break;
				printf("A %d\n", pw);
				fflush(stdout);
				scanf("%d", &t);
				if (!t) break;
			}
			e--;
			pw /= p;
			prd *= pw;
		}
	}
	if (prd > 1) {
		for (int i = 1; i <= tot; i++) if (pri[i] > sq && pri[i] <= n) {
			printf("A %d\n", pri[i]);
			fflush(stdout);
			int t;
			scanf("%d", &t);
			if (t > 1) {
				prd *= pri[i];
				break;
			}
		}
		printf("C %d\n", prd);
	} else {
		vector<int> vp;
		for (int i = 1; i <= tot; i++) if (pri[i] > sq && pri[i] <= n) {
			vp.push_back(pri[i]);
		}
		int cb = (vp.size() + 99) / 100;
		for (int i = 0; i < cb; i++) {
			int l = i * 100, r = min((i + 1) * 100 - 1, (int)vp.size() - 1);
			for (int k = l; k <= r; k++) {
				printf("B %d\n", vp[k]);
				fflush(stdout);
				scanf("%*d");
			}
			int t;
			printf("A %d\n", 1);
			fflush(stdout);
			scanf("%d", &t);
			if (t != ((int)vp.size() - r)) {
				for (int k = l; k <= r; k++) {
					printf("A %d\n", vp[k]);
					fflush(stdout);
					scanf("%d", &t);
					if (t) {
						prd = vp[k];
						break;
					}
				}
				break;
			}
		}
		printf("C %d\n", prd);
	}
	return 0;
}