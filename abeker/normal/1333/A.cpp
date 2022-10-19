#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int N, M;
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				printf("%c", "WB"[i || j]);
			puts("");
		}
	}
	return 0;
}