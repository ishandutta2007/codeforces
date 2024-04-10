#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int N, K, L;
		scanf("%d%d%d", &N, &K, &L);
		bool has = false;
		while (K--) {
			int x;
			scanf("%d", &x);
			if (x == N)
				has = true;
		}
		while (L--)
			scanf("%*d");
		puts(has ? "YES" : "NO");
	}
	return 0;
}