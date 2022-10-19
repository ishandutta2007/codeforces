#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int N, X;
		scanf("%d%d", &N, &X);
		int mx = 0;
		bool has = false;
		while (N--) {
			int jump;
			scanf("%d", &jump);
			mx = max(mx, jump);
			has |= jump == X;
		}
		if (mx >= X)
			printf("%d\n", has ? 1 : 2);
		else
			printf("%d\n", (X - 1) / mx + 1);
	}
	return 0;
}