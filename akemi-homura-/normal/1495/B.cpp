#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, p[N], L[N], R[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	L[1] = R[n] = 1;
	int mx = 1;
	for (int i = 2; i <= n; i++) {
		L[i] = p[i - 1] < p[i] ? L[i - 1] + 1 : 1;
		mx = max(mx, L[i]);
	}
	for (int i = n - 1; i >= 1; i--) {
		R[i] = p[i + 1] < p[i] ? R[i + 1] + 1 : 1;
		mx = max(mx, R[i]);
	}
	int cm = 0;
	for (int i = 1; i <= n; i++) cm += L[i] == mx || R[i] == mx;
	if (cm > 1) {
		puts("0");
		return 0;
	}
	int ans = 0;
	for (int i = 2; i < n; i++) {
		if (p[i - 1] < p[i] && p[i + 1] < p[i]) {
			if (L[i] == R[i] && (L[i] % 2 == 1) && L[i] == mx) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}