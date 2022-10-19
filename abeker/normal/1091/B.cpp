#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N;
int x[MAXN], y[MAXN];
int a[MAXN], b[MAXN];

int get(int *p, int *q) {
	return *min_element(p, p + N) + *max_element(q, q + N);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", x + i, y + i);
	for (int i = 0; i < N; i++)
		scanf("%d%d", a + i, b + i);
	
	printf("%d %d\n", get(x, a), get(y, b));	
	
	return 0;
}