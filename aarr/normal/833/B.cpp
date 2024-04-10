#include <iostream>
using namespace std;

const int N = 35 * 1000 + 5, K = 55;
int n, k;

int a[N];
int lt[N];
int seg1[N * 4][K];
int seg2[N * 4][K];


void update(int l, int r, int p, int lv, int id = 1, int s = 0, int e = n + 1) {
	if (e <= l || r <= s) {
		return;
	}
	if (l <= s && e <= r) {
		seg1[id][lv] += p;
		seg2[id][lv] += p;
		return;
	}
	int md = (s + e) / 2;
	update(l, r, p, lv, id * 2, s, md);
	update(l, r, p, lv, id * 2 + 1, md, e);
	seg1[id][lv] = max(seg1[id * 2][lv], seg1[id * 2 + 1][lv]) + seg2[id][lv];
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= k; j++) {
			update(0, lt[a[i]], -1, j);
			update(0, i, 1, j);			
		}
		lt[a[i]] = i;
		for (int j = k; j > 0; j--) {
			int x = seg1[1][j - 1];
		//	cout << i << " " << j << " " << x << endl;
			update(i, i + 1, x, j);
			
		}
	}
	cout << seg1[1][k];
	return 0;
}