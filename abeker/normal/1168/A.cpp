#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int N, M;
int a[MAXN];

bool check(int val) {
	int prev = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] + val < prev)
			return false;
		if (a[i] > prev && M - a[i] + prev > val)
			prev = a[i];
	}
	return true;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)	
		scanf("%d", a + i);
	
	int lo = 0, hi = M;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	printf("%d\n", lo);
	
	return 0;
}