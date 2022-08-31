#include <bits/stdc++.h>

using namespace std;

int f[10][10];
int s[10][10];

int main() {
	//freopen("input.txt", "r", stdin);
	int r, c, n, k;
	cin >> r >> c >> n >> k; 
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x--, y--;
		f[x][y] = 1;
	}
	int ans = 0;
	int t = 0;
	set <pair <int, int> > g;
	for (int x1 = 0; x1 < r; x1++) {
		for (int y1 = 0; y1 < c; y1++) {
			for (int len_x = 0; x1 + len_x <= r; len_x++) {
				for (int len_y = 0; y1 + len_y <= c; len_y++) {
					t = 0;
					for (int i = x1; i < x1 + len_x; i++) {
						for (int j = y1; j < y1 + len_y; j++) {
							t += f[i][j];
						}
					}
					ans += (t >= k);
				}
			}
		}
	}
	cout << ans << endl;
}