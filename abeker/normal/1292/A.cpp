#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, Q;
bool lava[2][MAXN];
int cnt;

int get(int r, int c) {
	int res = 0;
	for (int i = -1; i <= 1; i++)
		res += lava[r][c] && lava[r ^ 1][c + i];
	return res;
}

void toggle(int r, int c) {
	cnt -= get(r, c);
	lava[r][c] ^= 1;
	cnt += get(r, c);
}

int main() {
	scanf("%d%d", &N, &Q);
	while (Q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		toggle(x - 1, y);
		puts(cnt ? "No" : "Yes");
	}
	return 0;
}