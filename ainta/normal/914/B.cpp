#include<cstdio>
#include<algorithm>
using namespace std;
int w[101000], n, D[101000], C;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w + 1, w + n + 1);
	if (n == 1 || w[n] != w[n - 1]) {
		printf("Conan\n");
		return 0;
	}
	D[n] = 1;
	for (i = n - 1; i >= 1; i--) {
		if (w[i] == w[i + 1]) {
			if (C || !D[i + 1]) D[i] = 1;
			continue;
		}
		else {
			if (!D[i + 2])C = 1;
			if (C || !D[i + 1])D[i] = 1;
		}
	}
	if (D[1])printf("Conan\n");
	else printf("Agasa\n");
}