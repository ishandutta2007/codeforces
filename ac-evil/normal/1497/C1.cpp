#include <bits/stdc++.h>
//const int N = 100005;
int T, n, k;
int main() {
	//freopen("ques.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		if (n & 1) printf("%d %d %d\n", 1, n/2, n/2);
		else {
			n /= 2;
			if (n & 1) printf("%d %d %d\n", n - 1, n - 1, 2);
			else printf("%d %d %d\n", n, n/2, n/2);
		}
	}
	return 0;
}