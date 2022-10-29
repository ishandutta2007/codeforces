#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e3 + 5;

int n;
int a[N], b[N];
boolean visL[N], visR[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
	}
	int ans = 0;
	for (int l = 0; l <= n; l++) {
		if (visL[a[l]])
			break;
		if (l) visL[a[l]] = true;
		memset(visR, false, sizeof(visR));
		ans = max(ans, l);
		for (int r = n; r > l; r--) {
			if (visL[a[r]] || visR[a[r]])
				break;
			visR[a[r]] = true;
			ans = max(ans, l + n - r + 1);
		}
	}
	printf("%d\n", n - ans);
	return 0;
}