#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 105;

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

int n;
int p[N];
int f[N][N][2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", p + i);
	}
	int odd = (n + 1) >> 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j][0] = f[i][j][1] = N;
		}
	}
	if (p[1]) {
		f[1][p[1] & 1][p[1] & 1] = 0;
	} else {
		f[1][0][0] = 0;
		f[1][1][1] = 0;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= odd; j++) {
			if (p[i]) {
				f[i][j + (p[i] & 1)][p[i] & 1] = smin(f[i][j + (p[i] & 1)][p[i] & 1], f[i - 1][j][0] + (p[i] & 1), f[i - 1][j][1] + !(p[i] & 1));
			} else {
				f[i][j][0] = smin(f[i][j][0], f[i - 1][j][0], f[i - 1][j][1] + 1);
				f[i][j + 1][1] = smin(f[i][j + 1][1], f[i - 1][j][1], f[i - 1][j][0] + 1);
			}
		}
	}
	int ans = min(f[n][odd][0], f[n][odd][1]);
	printf("%d\n", ans);
	return 0;
}