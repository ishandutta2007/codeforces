#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	int t = 1;
	while (n - ((t - 1) << 1) > 1) {
		for (int i = 1; i <= m; i++) {
			printf("%d %d\n", t, i);
			printf("%d %d\n", n - t + 1, m - i + 1);
		}
		t++;
	} 
	if (n & 1) {
		for (int i = 1; i <= m; i++) {
			if (i & 1) {
				printf("%d %d\n", t, (i >> 1) + 1);
			} else {
				printf("%d %d\n", t, m - (i >> 1) + 1);
			}
		}	
	}
	return 0;
}