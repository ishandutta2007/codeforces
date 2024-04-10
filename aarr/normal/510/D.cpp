#include <iostream>
#include <vector>
using namespace std;

const int N = 305, M = 1030;
const int inf = 1000 * 1000 * 1000 + 7;

int c[N];
int l[N];
int dp[N][M];
vector <int> pr[N];
vector <int> a[N][N];

int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 2; j * j <= l[i]; j++) {
			if (l[i] % j == 0) {
				pr[i].push_back(j);
			//	cout << "73 " << i << " " << j << endl;
			}
			while (l[i] % j == 0) {
				l[i] /= j;
			}
		}
		if (l[i] > 1)
			pr[i].push_back(l[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < pr[i].size(); k++) {
				bool b = true;
				for (int q = 0; q < pr[j].size(); q++) {
					if (pr[i][k] == pr[j][q]) {
					//	shr[i][j].push_back(k);
						b = false;
					}
				}
				if (b) {
					a[i][j].push_back(k);
				//	cout << i << " " << j << " " << k << " " << pr[i][k] << endl;
				}
			}
		}
	}
	int ans = inf;
	for (int i = 0; i < n; i++) {
		for (int mask = 1; mask < (1 << pr[i].size()); mask++) {
			dp[i][mask] = inf;
			for (int j = 0; j < n; j++) {
				if (i != j) {
					int mask2 = mask;
					for (auto k : a[i][j]) {
						if (get(mask, k)) {
							mask2 -= 1 << k;
						}
					}
					dp[i][mask] = min(dp[i][mask], dp[i][mask2] + c[j]);
				//	cout << i << " " << mask << " " << j << " " << mask2 << " " << dp[i][mask] << endl;
				}
			}
		}
		ans = min(ans, dp[i][(1 << pr[i].size()) - 1] + c[i]);
	}
	if (ans == inf)
		cout << -1;
	else
		cout << ans;
	return 0;
}