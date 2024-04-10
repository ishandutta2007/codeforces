#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int N, D;
		scanf("%d%d", &N, &D);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int x;
			scanf("%d", &x);
			while (x--) 
				if (i <= D) {
					ans++;
					D -= i;
				}
		}
		printf("%d\n", ans);
	}
	return 0;
}