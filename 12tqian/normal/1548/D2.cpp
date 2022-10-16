#include <bits/stdc++.h>

using namespace std;

const int N = 6000;
const int D = 1450;

int c[N][4][4][4];
short gc[D][D];

int fast_gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	if (a < D) {
		return gc[a][b];
	} else if (b == 0) {
		return a;
	} else {
		return fast_gcd(b, a % b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<array<int, 2>> p(n);
	for (short i = 0; i < D; ++i) {
		gc[i][i] = i;
		for (short j = 0; j < i; ++j) {
			gc[i][j] = gc[j][i] = (j == 0 ? i : gc[j][i % j]);
		}
	}
	for (short i = 0; i < n; ++i) {
		for (short j = 0; j < 2; ++j) {
			cin >> p[i][j];
		}
	}
	for (short i = 0; i < n; ++i) {
		for (short j = 0; j < i; ++j) {
			short g = fast_gcd(abs(p[i][0] - p[j][0]), abs(p[i][1] - p[j][1])) & 3;
			++c[i][p[j][0] & 3][p[j][1] & 3][g];
			++c[j][p[i][0] & 3][p[i][1] & 3][g];
		}
	}
	for (short i = 0; i < n; ++i) {
		for (short j = 0; j < 2; ++j) {
			p[i][j] = p[i][j] & 3;
		}
	}
	auto area = [&](short a, short b, short c, short d, short e, short f) {
		return abs(a * d + c * f + e * b - b * c - d * e - f * a) & 3;
	};
	long long eee = 0;
	long long ooe = 0;
	short b3;
	int t;
	for (short i = 0; i < n; ++i) {
		for (short s1 = 0; s1 < 16; ++s1) {
			for (short s2 = s1; s2 < 16; ++s2) {
				short x1 = s1 >> 2;
				short y1 = s1 & 3;
				short x2 = s2 >> 2;
				short y2 = s2 & 3;
				if ((x1 & 1) != (x2 & 1) || (y1 & 1) != (y2 & 1)) {
					continue;
				}
				for (short b1 = 0; b1 < 4; ++b1) {
					int f1 = s1 < s2 ? (b1 & 1) : b1;
					for (short b2 = f1; b2 < 4; b2 += 2) {
						if (x1 == x2 && y1 == y2) {
							b3 = 0;
							if (b1 == b2) {
								t = c[i][x1][y1][b1] * (c[i][x1][y1][b1] - 1) >> 1;
							} else {
								t = c[i][x1][y1][b1] * c[i][x2][y2][b2];
							}
						} else {
							b3 = 2;
							t = c[i][x1][y1][b1] * c[i][x2][y2][b2];
						}
						short b = (b1 + b2 + b3) & 3;
						if (area(p[i][0], p[i][1], x1, y1, x2, y2) == b) {
							if ((b1 & 1) + (b2 & 1) == 0) {
								eee += t;
							} else {
								ooe += t;
							}
						}
					}
				}
			}
		}
	}
	long long ans = eee / 3 + ooe;
	cout << ans << '\n';
	return 0;
}