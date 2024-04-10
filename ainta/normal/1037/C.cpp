#include<cstdio>
#include<algorithm>
#define N_ 1010000
using namespace std;
char p[N_], q[N_];
int n, w[N_], res;
int main() {
	int i, j;
	scanf("%d", &n);
	scanf("%s%s", p, q);
	for (i = 0; i < n; i++) {
		if (p[i] != q[i]) {
			w[i] = 1;
			res++;
		}
	}
	for (i = 0; i < n; i++) {
		if (!w[i]) continue;
		for (j = i; j < n; j++) {
			if (!w[j])break;
			if (j > i && p[j] == p[j - 1])break;
		}
		int b = i, e = j - 1;
		res -= (e - b + 1) / 2;
		i = j - 1;
	}
	printf("%d\n", res);
}