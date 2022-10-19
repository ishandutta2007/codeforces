#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

void solve() {
	for (int i = 1; i < N; i++)
		if (abs(a[i] - a[i - 1]) >= 2) {
			printf("YES\n%d %d\n", i, i + 1);
			return;
		}
	puts("NO");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}