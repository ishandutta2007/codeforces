#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
int chd[50003] = { 0 };
int main() {
	int n, st, x, max, midx, k, i, val, nxt, ans = -1, t;
	int rng;
	srand(time(NULL));
	scanf("%d %d %d", &n, &st, &x);
	if (n < 1000) {
		for (i = 1; i <= n; i++) {
			printf("? %d\n", i);
			fflush(stdout);
			scanf("%d %d", &val, &nxt);
			if (val >= x) {
				if (ans == -1) ans = val;
				else ans = (ans < val ? ans : val);
			}
		}
		printf("! %d\n", ans);
		fflush(stdout);
		return 0;
	}
	else {
		k = (int)(sqrt((long double)(15 * n)));
		printf("? %d\n", st);
		fflush(stdout);
		scanf("%d %d", &val, &nxt);
		if (val >= x) {
			printf("! %d\n", val);
			fflush(stdout);
			return 0;
		}
		else {
			max = val;
			midx = st;
		}
		for (i = 0; i < k; i++) {
			rng = (rand()*RAND_MAX + rand()) % n + 1;
			if (!chd[rng]) {
				printf("? %d\n", rng);
				fflush(stdout);
				scanf("%d %d", &val, &nxt);
				chd[rng] = 1;
				if (nxt > 0) chd[nxt] = 1;
				if (val < x) {
					if (max < val) {
						max = val;
						midx = rng;
					}
				}
			}
			else i--;
		}
		t = midx;
		while (1) {
			printf("? %d\n", t);
			fflush(stdout);
			scanf("%d %d", &val, &nxt);
			if (val >= x) break;
			t = nxt;
			if (t == -1) break;
		}
		if (t == -1) {
			printf("! -1");
			fflush(stdout);
			return 0;
		}
		else {
			printf("! %d", val);
			fflush(stdout);
			return 0;
		}
	}
	
}