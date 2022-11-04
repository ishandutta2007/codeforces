#include <bits/stdc++.h>
using namespace std;
int cnt[2][2];
inline int gb(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) return 0;
	else return 1;
}
inline long long C3(int n) {
	return 1ll * n * (n - 1) * (n - 2) / 6;
}
inline long long C2(int n) {
	return 1ll * n * (n - 1) / 2;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		cnt[(x / 2) % 2][(y / 2) % 2]++;
	}
	long long ans = 0;
	for (int a = 0; a < 4; a++) for (int b = a; b < 4; b++) for (int c = b; c < 4; c++) {
		int x1 = a / 2, y1 = a % 2;
		int x2 = b / 2, y2 = b % 2;
		int x3 = c / 2, y3 = c % 2;
		if ((1 + gb(x1, y1, x2, y2) + gb(x1, y1, x3, y3) + gb(x3, y3, x2, y2)) % 2) {
			if (a == b && b == c) ans += C3(cnt[x1][y1]);
			else if (a == b) ans += C2(cnt[x1][y1]) * cnt[x3][y3];
			else if (b == c) ans += C2(cnt[x2][y2]) * cnt[x1][y1];
			else ans += 1ll * cnt[x1][y1] * cnt[x2][y2] * cnt[x3][y3];
		}
	}
	printf("%lld\n", ans);
	return 0;
}