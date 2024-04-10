#include<cstdio>
#include<algorithm>
using namespace std;
int n, Deg[101000];
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		Deg[a]++, Deg[b]++;
	}
	for (i = 1; i <= n; i++) {
		if (Deg[i] == 2) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}