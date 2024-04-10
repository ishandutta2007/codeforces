#include<cstdio>
#include<algorithm>
using namespace std;
int n, s, Deg[101000], c;
int main() {
	int a, b, i;
	scanf("%d%d", &n, &s);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		Deg[a]++, Deg[b]++;
	}
	if (n == 2) {
		printf("%d\n", s);
		return 0;
	}
	for (i = 1; i <= n; i++)if (Deg[i] == 1)c++;
	printf("%.10f\n",2.0*s / c);
}