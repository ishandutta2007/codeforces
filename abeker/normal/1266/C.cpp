#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5;

int N, M;
int row[MAXN], col[MAXN];

int main() {
	scanf("%d%d", &N, &M);
	
	if (N == 1 && M == 1) {
		puts("0");
		return 0;
	}
	
	for (int i = 1; i <= N; i++)
		row[i] = i;
	for (int j = 1; j <= M; j++)
		col[j] = N + j;
	
	if (M == 1) {
		col[1] = 1;
		for (int i = 1; i <= N; i++)
			row[i] = i + 1;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			printf("%d ", row[i] * col[j] / __gcd(row[i], col[j]));
		puts("");
	}
	
	return 0;
}