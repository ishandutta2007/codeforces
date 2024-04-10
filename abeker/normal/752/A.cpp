#include <cstdio>
using namespace std;

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K); K--;
	printf("%d %d %c\n", (K / 2) / M + 1, (K / 2) % M + 1, "LR"[K % 2]);
	return 0;
}