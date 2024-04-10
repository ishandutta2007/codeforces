#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	puts("2");
	for (int i = 1; i < N; i++)
		printf("%lld\n", (long long)(i + 1) * (i + 2) * (i + 2) - i);
	return 0;
}