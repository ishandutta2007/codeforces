#include<cstdio>
#include<algorithm>
using namespace std;
char p[5010];
int B[5010], E[5010];
int n;
int main() {
	int i, j;
	scanf("%s", p);
	for (i = 0; p[i]; i++);
	n = i;
	for (i = 0; i < n; i++) {
		int s = 0;
		for (j = i; j < n; j++) {
			if (p[j] == ')')s--;
			else s++;
			if (s < 0)break;
		}
		B[i] = j;
	}
	for (i = 0; i < n; i++) {
		int s = 0;
		for (j = i; j >= 0; j--) {
			if (p[j] == '(')s--;
			else s++;
			if (s < 0)break;
		}
		E[i] = j;
	}
	int r = 0;
	for (i = 0; i < n; i++)for (j = i+1; j < n; j+=2) {
		if (B[i] > j && E[j] < i)r++;
	}
	printf("%d\n", r);
}