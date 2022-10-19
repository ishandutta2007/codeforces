#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, K;
int dad[MAXN], rnk[MAXN];

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rnk[x] > rnk[y])
		swap(x, y);
	dad[x] = y;
	rnk[y] += rnk[x] == rnk[y];
}

int main() {
	scanf("%d%d", &N, &K);	
	for (int i = 1; i <= N; i++)
		dad[i] = i;
	for (int i = 0; i < K; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		join(x, y);
	}
	
	int comps = 0;
	for (int i = 1; i <= N; i++)
		comps += find(i) == i;
	
	printf("%d\n", K - N + comps);
	
	return 0;
}