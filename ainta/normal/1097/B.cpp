#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int w[16];
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &w[i]);
	for (i = 0; i < (1 << n); i++) {
		int s = 0;
		for (j = 0; j < n; j++) {
			if ((i >> j) & 1)s += w[j];
			else s -= w[j];
		}
		if (s < 0)s = -s;
		if (s % 360 == 0) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}