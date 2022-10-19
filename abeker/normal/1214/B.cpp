#include <bits/stdc++.h>
using namespace std;

int main() {
	int B, G, N;
	scanf("%d%d%d", &B, &G, &N);
	
	int bad = 0;
	for (int i = 0; i <= N; i++)
		if (i > B || N - i > G)
			bad++;
	
	printf("%d\n", N + 1 - bad);
	
	return 0;
}