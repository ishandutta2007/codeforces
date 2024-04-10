#include <bits/stdc++.h>
using namespace std;

int cnt[6006][4][4][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (auto &e : p) cin >> e.first >> e.second;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int x = (p[i].first - p[j].first) & 3;
			int y = (p[i].second - p[j].second) & 3;
			int b = __gcd(abs(p[i].first - p[j].first), abs(p[i].second - p[j].second)) % 4;
			cnt[i][x][y][b]++;
		}
	}

	long long res_one = 0;
	long long res_three = 0;

	auto add = [&](int i, int x, int y, int xx, int yy, int b0, int b1) {
		int val = 0;
		if (x != xx || y != yy || b0 != b1) {
			val = cnt[i][x][y][b0] * cnt[i][xx][yy][b1];
		} else {
			val = cnt[i][x][y][b0] * (cnt[i][x][y][b0] - 1) / 2;
		}
		if (b0 & 1) res_one += val;
		else res_three += val;
 	};

	for (int i = 0; i < n; i++) {
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				for (int xx = x; xx < 4; xx += 2) {
					for (int yy = (xx == x ? y : 0); yy < 4; yy++) {
						if ((y & 1) != (yy & 1)) continue;
						int S = abs(x * yy - xx * y) % 4;
						if (S & 1) continue;
						int b = ((x == xx && y == yy) ? 0 : 2);
						int target = S - b + (S < b ? 4 : 0);
						for (int b0 = 0; b0 < 4; b0++) {
							if (cnt[i][x][y][b0] == 0) continue;
							int b1 = target - b0 + (target < b0 ? 4 : 0);
							if (cnt[i][xx][yy][b1] == 0) continue;
							if (x == xx && y == yy && b1 < b0) continue; 
							add(i, x, y, xx, yy, b0, b1);
						}
					}
				}
			}
		}
	}
	cout << res_one + res_three / 3 << '\n';

	return 0;
}