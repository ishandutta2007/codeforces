#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N;
int a[MAXN];
ll left[MAXN], right[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++)
		scanf("%d", a + i);
}

ll solve() {
	for (int i = 1; i < N; i++)
		if (a[i] > 1)
			left[i] = left[i - 1] + a[i] - a[i] % 2;
	for (int i = N - 2; i >= 0; i--)
		if (a[i + 1] > 1)
			right[i] = right[i + 1] + a[i + 1] - a[i + 1] % 2;
	
	ll sum = 0, sol = 0, mx = 0;
	for (int i = 1; i < N; i++) {		
		sum += a[i] + a[i] % 2 - 1;
		mx = max(mx, left[i] - sum); 
		sol = max(sol, mx + sum + right[i]);
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}