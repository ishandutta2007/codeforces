#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
int a[MAXN];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) 
		scanf("%d", a + i);
		
	sort(a, a + N);
	
	int curr = 0;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		curr = min(curr + 1, a[i]);
		if (i < N - 1)
			ans += a[i] - 1;
	}
	
	printf("%lld\n", ans + curr - 1);
		
	return 0;
}