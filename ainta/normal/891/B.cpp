#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[23], P[23];
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &P[i]);
		w[i] = P[i];
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)if (P[i] == w[j])break;
		printf("%d ",w[j%n + 1]);
	}
}