#include<cstdio>
#include<algorithm>
#define N_ 301000
using namespace std;
char p[5010], q[5010];
int n;
int main(){
	int i, j;
	scanf("%s", p);
	for (i = 0; p[i]; i++);
	n = i;
	int ck = 0;
	for (i = 0; i < n - 1; i++) {
		if (p[i] != p[i + 1])ck = 1;
	}
	if (!ck) {
		printf("Impossible\n");
		return 0;
	}
	if (n % 2 == 1) {
		ck = 0;
		for (i = 0; i < n; i++) {
			if (i != n / 2 && p[i] != p[0]) {
				ck = 1;
			}
		}
		if (!ck) {
			printf("Impossible\n");
			return 0;
		}
	}
	for (i = 1; i < n; i++) {
		int c = 0;
		for (j = i; j < n; j++)q[c++] = p[j];
		for (j = 0; j < i; j++)q[c++] = p[j];
		int ck = 0;
		for (j = 0; j < n; j++) {
			if (q[j] != q[n - j - 1])break;
			if (q[j] != p[j])ck = 1;
		}
		if (j == n && ck) {
			printf("%d\n", 1);
			return 0;
		}
	}
	printf("%d\n", 2);
}