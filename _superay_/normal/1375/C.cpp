#include <bits/stdc++.h>
using namespace std;
int n, a[300005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		if (a[1] < a[n]) puts("YES");
		else puts("NO");
	}
	return 0;
}