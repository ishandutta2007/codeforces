#include<cstdio>
#include<algorithm>
using namespace std;
int n, a, b, w[201000];
void Solve() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 1; i < n; i++) {
		if (abs(w[i + 1] - w[i]) > 1) {
			puts("YES");
			printf("%d %d\n", i, i + 1);
			return;
		}
	}
	puts("NO");
}
int main() {
	int TC, t;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}