#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[1010000];
int n;
long long A[1010000], B[1010000], res;
int main() {
	int i;
	scanf("%s", p+1);
	for (i = 1; p[i]; i++);
	n = i - 1;
	int c = 0;
	for (i = 1; i <= n; i++) {
		if (p[i] == 'v'&&p[i - 1] == 'v')c++;
		A[i] = c;
	}
	c = 0;
	for (i = n; i >= 1; i--) {
		if (p[i] == 'v'&&p[i + 1] == 'v')c++;
		B[i] = c;
	}
	for (i = 1; i <= n; i++) {
		if (p[i] == 'o')res += A[i - 1] * B[i + 1];
	}
	printf("%lld\n", res);
}