#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[110], Mx;
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		Mx = max(Mx, w[i]);
	}
	for (i = Mx;; i++) {
		int s = 0;
		for (j = 1; j <= n; j++) {
			s += i - w[j] * 2;
		}
		if (s > 0) {
			printf("%d\n", i);
			return 0;
		}
	}
}