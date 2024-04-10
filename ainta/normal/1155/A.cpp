#include<cstdio>
#include<algorithm>
using namespace std;
int n, pv;
char p[301000], Mx;
int main() {
	int i;
	scanf("%d", &n);
	scanf("%s", p);
	for (i = 1; i<n; i++) {
		if (p[i] < p[i - 1]) {
			printf("YES\n%d %d\n", i, i + 1);
			return 0;
		}
	}
	puts("NO");
}