#include <iostream>
using namespace std;

const int N = 43, M = 21;

int adj1[N], adj2[N], adj12[N];

bool cm[1 << M];
int dp1[1 << M], dp2[1 << M];


int get(int x, int y) {
	return (x >> y) & 1;
}

int main() {
	int n, k;
	cin >> n >> k;
	int n2 = n / 2, n1 = n - n2;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			int x;
			cin >> x;
			adj1[i] ^= (1 << j) * x;
		}
		adj1[i] ^= 1 << i;
		for (int j = 0; j < n2; j++) {
			int x;
			cin >> x;
			adj12[i] ^= (1 << j) * x;
		}
	}
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n1; j++) {
			int x;
			cin >> x;
		}
		adj2[i] ^= (1 << i);
		for (int j = 0; j < n2; j++) {
			int x;
			cin >> x;
			adj2[i] ^= (1 << j) * x;
		}
	}
	for (int mask = 1; mask < (1 << n2); mask++) {
		for (int i = 0; i < n2; i++) {
			if (get(mask, i)) {
				int mask2 = mask ^ (1 << i);
				dp2[mask] = max(dp2[mask], dp2[mask2]);
				if (dp2[mask2] == __builtin_popcount(mask2) && (adj2[i] & mask2) == mask2) {
					dp2[mask] = __builtin_popcount(mask);
				}
			}
		}
	}
//	cout << "74 " << n1 << " " << n2 << " " << (1 << n2) - 1 << endl;
	int ans = 0;
	cm[0] = true;
	dp1[0] = (1 << n2) - 1;
//	cout << "75 " << dp1[0] << " " << adj12[0] << endl;
	for (int mask = 1; mask < (1 << n1); mask++) {
		int v = __builtin_ctz(mask);
		int mask2 = mask ^ (1 << v);
		dp1[mask] = dp1[mask2] & adj12[v];
		if (cm[mask2] && (mask2 & adj1[v]) == mask2) {
	//		cout << "73 " << mask << " " << dp1[mask] << " " << dp2[dp1[mask]] << endl;
			cm[mask] = true;
			ans = max(ans, __builtin_popcount(mask) + dp2[dp1[mask]]);
		}
	}
	ans = max(ans, dp2[dp1[0]]);
//	cout << ans << endl;
	cout << fixed;
	cout << (double) k * k * (ans - 1) / ans / 2;
	return 0;
}