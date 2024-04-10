#include<cstdio>
#include<algorithm>
using namespace std;
int n, Q;
int main() {
	int i;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d", &n);
		int t = 1;
		while (t < n)t = t * 2 + 1;
		if (t == n) {
			int r;
			for (i = 2; i*i <= n; i++) {
				if (n%i == 0)break;
			}
			if (i*i > n)r = 1;
			else r = n / i;
			printf("%d\n", r);
		}
		else {
			printf("%d\n", t);
		}
	}
}