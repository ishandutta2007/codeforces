#include <bits/stdc++.h>
using namespace std;
int good[10];
int h, m;
inline bool isval(int x, int y) {
	if (good[x / 10] == -1 || good[x % 10] == -1 || good[y / 10] == -1 || good[y % 10] == -1) return false;
	return good[y % 10] * 10 + good[y / 10] < h && good[x % 10] * 10 + good[x / 10] < m;
}
int main() {
	memset(good, -1, sizeof(good));
	good[0] = 0;
	good[1] = 1;
	good[2] = 5;
	good[5] = 2;
	good[8] = 8;
	int T;
	scanf("%d", &T);
	while (T--) {
		char str[100];
		scanf("%d%d %s", &h, &m, str);
		int x = (str[0] - '0') * 10 + (str[1] - '0');
		int y = (str[3] - '0') * 10 + (str[4] - '0');
		while (!isval(x, y)) {
			if (y < m - 1) y++;
			else {
				y = 0;
				if (x < h - 1) x++;
				else x = 0;
			}
		}
		printf("%02d:%02d\n", x, y);
	}
	return 0;
}