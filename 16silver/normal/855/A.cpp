#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
char c[100][111];
int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%s", c[i]);
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (strcmp(c[i], c[j]) == 0) break;
		}
		if (j == i) printf("NO\n");
		else printf("YES\n");
	}
}