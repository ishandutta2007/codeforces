#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5, SQ = 320, LG = 23;

int a[N];
int b[SQ];
int c[SQ][LG];
int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < LG; j++) {
			if (get(a[i], j)) {
				c[i / SQ][j]++;
			}
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int qt, l, r;
		cin >> qt >> l >> r;
		l--;
		r--;
		if (qt == 2) {
			int x;
			cin >> x;
			while (l <= r) {
				if (l % SQ == 0 && l + SQ <= r) {
					for (int j = 0; j < LG; j++) {
						if (get(x, j)) {
							c[l / SQ][j] = SQ - c[l / SQ][j];
						}
					}
					b[l / SQ] ^= x;
				//	cout << 489 << " " << b[l / SQ] << endl;
					l += SQ;
				}
				else {
					for (int j = 0; j < LG; j++) {
						if (get(x, j)) {
							if (get(a[l] ^ b[l / SQ], j)) {
								c[l / SQ][j]--;
							}
							else {
								c[l / SQ][j]++;
							}
						}
					}
					a[l] ^= x;
					l++;
				}
			}
		}
		else {
			long long ans = 0;
			while (l <= r) {
				if (l % SQ == 0 && l + SQ <= r) {
					for (int j = 0; j < LG; j++) {
						ans += 1ll * c[l / SQ][j] * (1 << j);
					}
					l += SQ;
				//	cout << 73 << endl;
				}
				else {
					ans += a[l] ^ b[l / SQ];
					l++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}