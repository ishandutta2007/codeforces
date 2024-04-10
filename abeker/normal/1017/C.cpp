#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	int len = sqrt((double)N);
	int num = len;
	while (1) {
		if (num >= N) {
			for (int j = N; j > num - len; j--)
				printf("%d ", j);
			puts("");
			break;
		}
		for (int j = 0; j < len; j++)
			printf("%d ", num - j);
		num += len;
	}
	
	return 0;
}