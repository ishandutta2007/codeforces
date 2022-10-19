#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N;
int b[MAXN];
ll a[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", b + i);
}

void solve() {
	int pos = -1;
	for (int i = 0; i < N; i++)
		if (b[i] > b[(i - 1 + N) % N])
			pos = i;
	
	if (pos == -1) {
		if (b[0]) {
			puts("NO");
			return;
		}
		puts("YES");
		for (int i = 0; i < N; i++)
			printf("1 ");
		puts("");
		return;
	}
	
	a[pos] = b[pos];
	for (int i = 1; i < N; i++) {
		pos = (pos - 1 + N) % N;
		a[pos] = b[pos] + (max((b[(pos - 1 + N) % N] - b[pos]) / a[(pos + 1) % N], 0ll) + 1) * a[(pos + 1) % N];
	}
	
	puts("YES");
	for (int i = 0; i < N; i++)
		printf("%lld ", a[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}