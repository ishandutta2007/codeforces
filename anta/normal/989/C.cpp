#include "bits/stdc++.h"
using namespace std;

int main() {
	int A; int B; int C; int D;
	while (~scanf("%d%d%d%d", &A, &B, &C, &D)) {
		int xs[] = { A, B, C, D };
		int H = 40, W = 40;
		vector<string> ans(H, string(W, 0));
		for (int k = 0; k < 4; ++ k) {
			for (int i = 0; i < H / 4; ++ i) for (int j = 0; j < W; ++ j)
				ans[H / 4 * k + i][j] = "ABCD"[k];
		}
		for (int k = 0; k < 4; ++ k) {
			int top = (k + 2) % 4 * (H / 4);
			int y = top, x = 0;
			for (int t = 0; t < xs[k] - 1; ++ t) {
				ans[y][x] = "ABCD"[k];
				x += 2;
				if (x == W) {
					y += 2;
					x = 0;
				}
			}
		}
		printf("%d %d\n", H, W);
		for (int i = 0; i < H; ++ i)
			puts(ans[i].c_str());
	}
}