#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5;
const int MAGIC[3][3] = {1, 2, 4, 5, 3, 8, 9, 6, 7};

int N;
int ans[MAXN][MAXN];

int main() {
	scanf("%d", &N);
	
	if (N <= 2) {
		puts("-1");
		return 0;
	}

	int ptr = 0;
	for (int i = N; i; i--)
		if (i % 2)
			for (int j = 1; j <= N - 3; j++)
				ans[i][j] = ++ptr;
		else
			for (int j = N - 3; j; j--)
				ans[i][j] = ++ptr;
	
	for (int j = N; j >= N - 2; j--)
		if ((N - j) % 2)
			for (int i = N - 3; i; i--)
				ans[i][j] = ++ptr;
		else
			for (int i = 1; i <= N - 3; i++)
				ans[i][j] = ++ptr;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ans[N - 2 + i][N - 2 + j] = MAGIC[i][j] + N * N - 9;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%d ", ans[i][j]);
		puts("");
	}
	
	return 0;
}