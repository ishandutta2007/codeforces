#include <cstdio>
#include <vector>
#include <algorithm>
#define P 998244353LL
using namespace std;
long long bino[5003][5003];
long long fct[5003];
int main() {
	int a[3], i, j;
	long long p, q, r = 1;
	for (i = 0; i < 5002; i++) {
		bino[i][0] = 1;
		bino[i][i] = 1;
	}
	for (i = 0; i < 5002; i++) {
		for (j = 1; j < i; j++) {
			bino[i][j] = (bino[i - 1][j] + bino[i - 1][j - 1]) % P;
		}
	}
	fct[0] = 1;
	for (i = 1; i < 5002; i++) fct[i] = (fct[i - 1] * (long long)(i)) % P;
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	sort(a, a + 3);
	q = 0;
	for (i = 0; i <= a[0]; i++) {
		p = (bino[a[1]][a[0] - i] * bino[a[0]][i]) % P;
		p = (p*fct[a[0] - i]) % P;
		q = (q+p)%P;
	}
	r = (r*q) % P;
	q = 0;
	for (i = 0; i <= a[0]; i++) {
		p = (bino[a[2]][a[0] - i] * bino[a[0]][i]) % P;
		p = (p*fct[a[0] - i]) % P;
		q = (q+p)%P;
	}
	r = (r*q) % P;
	q = 0;
	for (i = 0; i <= a[1]; i++) {
		p = (bino[a[2]][a[1] - i] * bino[a[1]][i]) % P;
		p = (p*fct[a[1] - i]) % P;
		q = (q+p)%P;
	}
	r = (r*q) % P;
	printf("%lld", r%P);
}