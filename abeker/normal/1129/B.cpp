#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

int main() {
	int K;
	scanf("%d", &K);
	
	printf("%d\n", N);
	for (int i = 0; i < N - 2; i++)
		printf("0 ");
	
	int rem = N - 1 - K % (N - 1);
	
	printf("%d %d\n", -rem, (K + N * rem) / (N - 1));
	
	return 0;
}