#include <bits/stdc++.h>
using namespace std;

const int magic[4][4] = {8, 9, 1, 13,
												 3, 12, 7, 5,
												 0, 2, 4, 11,
												 6, 10, 15, 14};
 
int N, K;

int calc(int x, int y) {
	int idx = (x / 4) * K + (y / 4);
	return 16 * idx + magic[x % 4][y % 4];
}

int main() {
	scanf("%d", &N);
	K = N / 4;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", calc(i, j));
		puts("");
	}
	
	return 0;
}