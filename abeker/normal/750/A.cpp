#include <cstdio>
using namespace std;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		if (5 * i * (i + 1) / 2 + K > 240) {
			printf("%d\n", i - 1);
			return 0;
		}
	printf("%d\n", N);
	return 0;
}