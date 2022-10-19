#include <bits/stdc++.h>
using namespace std;
int best[11], t;
int main() {
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		fill_n(best, 11, 0);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int b, d;
			scanf("%d%d", &b, &d);
			best[d] = max(best[d], b);
		}
		int sum = 0, poss = 1;
		for (int i = 1; i <= 10; i++) {
			if (!best[i]) poss = 0;
			sum += best[i];
		}
		if (poss) printf("%d\n", sum);
		else printf("MOREPROBLEMS\n");
	}
}