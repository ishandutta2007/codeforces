#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	if (N == 1) {
		puts("1");
		return 0;
	}
	
	int pot = 1;
	for (; N > 3; N /= 2) {
		for (int i = 0; i < (N + 1) / 2; i++)
			printf("%d ", pot);
		pot *= 2;
	}
	
	if (N == 2)
		printf("%d %d\n", pot, 2 * pot);
	else
		printf("%d %d %d\n", pot, pot, 3 * pot);
	
	return 0;
}