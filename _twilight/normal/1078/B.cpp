#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>

const int N = 105, M = N * N;
int n;
int a[N];
int f[N][M];
vector<pii> b;

int main() {
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);		
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	b.push_back(pii(a[1], 1));
	for (int i = 2; i <= n; i++) {
		if (a[i] == b.back().first) {
			b.back().second++;
		} else {
			b.push_back(pii(a[i], 1));
		}
	}
	int m = b.size();
	if (m == 1) {
		printf("%d\n", n);
	} else {
		f[0][0] = 1;
		int sumc = 0;
		for (int i = 0; i < m; i++) {
			int x = b[i].first, y = b[i].second;
			sumc += y;
			for (int c = sumc; c; c--) {
				for (int j = sum; j >= x; j--) {
					for (int k = 1; k * x <= j && k <= y && k <= c && f[c][j] < 2; k++) {
						f[c][j] = min(2, f[c][j] + f[c - k][j - x * k]);
					}
				}
			}
		}
		if (m == 2) {
			int ans = 0;
			for (int i = 0; i < m; i++) {
				int x = b[i].first, y = b[i].second;
				for (int j = 1; j <= y; j++) {
					if (f[j][j * x] == 1) {
						if (j < y) {
							ans = max(ans, j);
						} else {
							ans = n;
						}
					}
				}
			}
			printf("%d\n", ans);
		} else {
			int ans = 0;
			for (int i = 0; i < m; i++) {
				int x = b[i].first, y = b[i].second;
				for (int j = 1; j <= y; j++) {
					if (f[j][j * x] == 1) {
						ans = max(ans, j);
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}