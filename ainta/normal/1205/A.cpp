#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[201000];
int main() {
	int i;
	scanf("%d", &n);
	if (n % 2 == 1) {
		puts("YES");
		for (i = 0; i < n; i++) {
			w[i] = i * 2 + i%2;
			w[i + n] = i * 2 + 1 - i%2;
		}
		for (i = 0; i < 2 * n; i++)printf("%d ", w[i] + 1);
		puts("");
	}
	else {
		puts("NO");
	}
}