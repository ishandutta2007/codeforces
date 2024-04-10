#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
long long res;
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			if ((i*i + j*j) % m == 0) {
				res += 1ll * ((n - i + m) / m) * ((n - j + m) / m);

			}
		}
	}
	printf("%lld\n", res);
}