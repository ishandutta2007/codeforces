#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n, q, c;
	int br[11][100][100];
	cin >> n >> q >> c;
	c++;
	for (int ti = 0; ti < 11 ; ti++) {
		for (int xi = 0; xi < 100; xi++) {
			for (int yi = 0; yi < 100; yi++) {
				br[ti][xi][yi] = -1;
			}
		}
	}
	int x, y, s;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> s;
		x--;
		y--;
		if (br[0][x][y] != -1) {
			for (int ti = 0; ti < c; ti++) {
				br[ti][x][y] += (s + ti) % c;
			}
		}
		else {
			for (int ti = 0; ti < c; ti++) {
				br[ti][x][y] = (s + ti) % c;
			}
		}
	}
	int sum[11][101][101];
	for (int ti = 1; ti < c; ti++) {
		for (int xi = 0; xi < 101; xi++) {
			for (int yi = 0; yi < 101; yi++) {
				sum[ti][xi][yi] = 0;
			}
		}
	}
	for (int ti = 0; ti < c; ti++) {
		for (int xi = 1; xi < 101; xi++) {
			for (int yi = 1; yi < 101; yi++) {
				if (br[ti][xi - 1][yi - 1] != -1) {
					sum[ti][xi][yi] = br[ti][xi - 1][yi - 1] + sum[ti][xi][yi - 1] + sum[ti][xi - 1][yi] - sum[ti][xi - 1][yi - 1];
				}
				else {
					sum[ti][xi][yi] = sum[ti][xi][yi - 1] + sum[ti][xi - 1][yi] - sum[ti][xi - 1][yi - 1];
				}
			}
		}
	}
	int t, x1, x2, y1, y2;
	for (int i = 0; i < q; i++) {
		cin >> t >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		t = t % c;
		cout << (sum[t][x2][y2] + sum[t][x1][y1] - sum[t][x1][y2] - sum[t][x2][y1]) << endl;
	}
}