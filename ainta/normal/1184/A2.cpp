#include<cstdio>
#include<algorithm>
using namespace std;
int n, OK[201000], U[201000];
char p[201000];
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int i, j;
	scanf("%d", &n);
	scanf("%s", p);
	for (i = 1; i <= n; i++) {
		if (n%i == 0) {
			OK[i] = 1;
			for (j = 0; j < i; j++)U[j] = 0;
			for (j = 0; j < n; j++) {
				U[j%i] ^= (p[j] - '0');
			}
			for (j = 0; j < i; j++)if (U[j])OK[i] = 0;
		}
	}
	int res = 0;
	for (i = 0; i < n; i++) {
		res += OK[gcd(n, i)];
	}
	printf("%d\n", res);
}