#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int a[MAXN];

int main() {
	scanf("%d", &N);
	long long sol = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", a + i);
		sol -= a[i];
		a[i]++;
	}
	
	for (int i = 1; i < N; i++)
		a[i] = max(a[i], a[i - 1]);
	
	int mx = -1e9;
	for (int i = N - 1; i >= 0; i--) {
		a[i] = max(a[i], mx + i);
		mx = max(mx, a[i] - i);
		sol += a[i];
	}
		
	printf("%lld\n", sol - N);
	
	return 0;
}