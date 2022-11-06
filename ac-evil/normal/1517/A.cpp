#include <bits/stdc++.h>
typedef long long LL;
int T; LL n;
int main() {
	// freopen("ques.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		int cnt = 0;
		for (int i = 15; ~i; i--) {
			LL tmp = 2050;
			for (int j = 1; j <= i; j++) tmp *= 10;
			while (n >= tmp) n -= tmp, cnt++;
		}
		printf("%d\n", n ? -1 : cnt);
	}
	return 0;
}