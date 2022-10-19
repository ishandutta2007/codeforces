#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, U;
int a[MAXN];

int main() {
	scanf("%d%d", &N, &U);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);

	double sol = -1;	
	a[N] = INT_MAX;
	for (int i = 0; i < N - 2; i++) {
		int pos = lower_bound(a, a + N, a[i] + U + 1) - a - 1;
		if (pos > i + 1 && a[pos] - a[i] <= U)
			sol = max(sol, (double)(a[pos] - a[i + 1]) / (a[pos] - a[i]));
	}
	
	printf("%.20lf\n", sol);
	
	return 0;
}