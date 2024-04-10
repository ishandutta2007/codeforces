#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int mini = N + 1;
	while (M--) {
		int l, r;
		scanf("%d%d", &l, &r);
		mini = min(mini, r - l + 1);
	}
	printf("%d\n", mini);
	for (int i = 0; i < N; i++)
		printf("%d ", i % mini);
	puts("");
	return 0;
}