#include <cstdio>
#include <cstdlib>
using namespace std;

void no() {
	puts("-1");
	exit(0);
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	
	if (K == 1) 
		no();
		
	if (N < 4)
		no();
	
	if (K > 3)
		no();
	
	if (N == 4 && K == 2)
		no();
	
	if (K == 2) {
		printf("%d\n", N - 1);
		for (int i = 1; i < N; i++)
			printf("%d %d\n", i, i + 1);
		return 0;
	}
	
	printf("%d\n", N - 1);
	puts("1 2");
	puts("2 3");
	for (int i = 4; i <= N; i++)
		printf("3 %d\n", i);
		
	return 0;
}