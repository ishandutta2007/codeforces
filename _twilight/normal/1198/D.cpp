#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 51;

int n;
char s[N][N];
int f[N][N][N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	for (int lu = 0; lu < n; lu++) {
		for (int u = 1; u + lu <= n; u++) {
			for (int ll = 0; ll < n; ll++) {	
				for (int l = 1; l + ll <= n; l++) {
					int d = u + lu, r = l + ll;
					if (u == d && l == r) {
						f[u][d][l][r] = (s[u][l] == '#');
						continue;
					}
					f[u][d][l][r] = max(d - u, r - l) + 1;
					for (int i = u; i < d; i++) {
						f[u][d][l][r] = min(f[u][d][l][r], f[u][i][l][r] + f[i + 1][d][l][r]);
					}
					for (int i = l; i < r; i++) {
						f[u][d][l][r] = min(f[u][d][l][r], f[u][d][l][i] + f[u][d][i + 1][r]);
					}
				}
			}
		}
	}
	printf("%d\n", f[1][n][1][n]);
	return 0;
}