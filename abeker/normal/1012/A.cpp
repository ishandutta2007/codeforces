#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 2 * N; i++)
		scanf("%d", a + i);
	
	sort(a, a + 2 * N);
	
	ll sol = (ll)(a[N - 1] - a[0]) * (a[2 * N - 1] - a[N]);
	for (int i = 1; i < N; i++)
		sol = min(sol, (ll)(a[i + N - 1] - a[i]) * (a[2 * N - 1] - a[0]));
	
	printf("%lld\n", sol);
	
	return 0;
}