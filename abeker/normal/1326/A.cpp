#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int N;
		scanf("%d", &N);
		if (N == 1) {
			puts("-1");
			continue;
		}
		printf("2");
		for (int i = 1; i < N; i++)
			printf("3");
		puts("");
	}
	return 0;
}