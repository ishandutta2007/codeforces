#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n, q;
int cnt[16];
boolean ban[16];
boolean acc[2][N];

int pack(int x) {
	int rt = 0;
	rt = acc[0][x];
	rt = rt * 2 + acc[0][x + 1];
	rt = rt * 2 + acc[1][x];
	rt = rt * 2 + acc[1][x + 1];
	return rt;
}

int main() {
	scanf("%d%d", &n, &q);
	ban[10] = ban[5] = ban[9] = ban[6] = ban[15 - 1] = ban[15 - 2] = ban[15 - 4] = ban[15 - 8] = ban[15] = true;
	cnt[0] = n - 1;
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		if (y > 1)	cnt[pack(y - 1)]--;
		if (y < n)	cnt[pack(y)]--;
		acc[x][y] ^= 1;
		if (y > 1)	cnt[pack(y - 1)]++;
		if (y < n)	cnt[pack(y)]++;
		boolean flag = true;
		for (int i = 0; i < 16; i++) {
			if (ban[i] && cnt[i]) {
				flag = false;
			}
		}
		puts((flag) ? ("Yes") : ("No"));
	}
	return 0;
}