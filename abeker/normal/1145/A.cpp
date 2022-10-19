#include <bits/stdc++.h>
using namespace std;

int N;
int a[20];

int solve(int lo, int hi) {
	bool ok = true;
	for (int i = lo + 1; i < hi; i++)
		ok &= a[i - 1] <= a[i];
	if (ok)
		return hi - lo;
	int mid = (lo + hi) / 2;
	return max(solve(lo, mid), solve(mid, hi));
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	printf("%d\n", solve(0, N));
	
	return 0;
}