#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200 * 1000 + 5, K = 22;

int t[K];
int a[K][K];
int lt[K];
pair <int, int> c[K];
long long dp[1 << K];
long long dp2[1 << K];
bool mark[1 << K];

int main() {
	int n, k, e, ans = 0, m0 = 0;
	string s;
	cin >> n >> k >> e;
	cin >> s;
	for (int i = 0; i < k; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cin >> a[i][j];
		}
	}
	fill(lt, lt + k, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			c[j] = {lt[j], j};
		}
		sort(c, c + k);
		int x = s[i] - 'A', mask = 0;
	//	for (int j = 0; j < k; j++) {
	//		cout << "74 " << i << " " << j << " " << lt[j] << endl;
	//	}
		for (int j = k - 1; j >= 0; j--) {
		//	cout << "71 " << i << " " << j << " " << c[j].first << " " << c[j].second << endl;
			if (c[j].first == -1) {
				break;
			}
			int y = c[j].second;
		//	cout << "72 " << i << " " << mask << " " << x << " " << y << endl;
			dp[mask] += a[y][x];
		//	cout << "74 " << mask << " " << y << " " << x << " " << a[y][x] << endl;
			if (x != y) {
				dp[mask ^ (1 << x)] -= a[y][x];
				dp[mask ^ (1 << y)] -= a[y][x];
				dp[mask ^ (1 << x) ^ (1 << y)] += a[y][x];				
			}
			else {
				dp[mask ^ (1 << x)] -= a[y][x];
			}
			if (y == x) {
				break;
			}
			mask ^= (1 << y);
		}
		lt[s[i] - 'A'] = i;
	}
//	for (int mask = 0; mask < (1 << k); mask++) {
//		cout << "75 " << mask << " " << dp[mask] << endl;
//	}
	for (int i = 0; i < k; i++) {
		if (lt[i] == -1) {
			m0 ^= (1 << i);
		}
		for (int mask = 0; mask < (1 << k); mask++) {
			if ((mask >> i) & 1) {
				dp[mask] += dp[mask ^ (1 << i)];
			}
		}
	}
	for (int mask = 1; mask < (1 << k); mask++) {
		int x = __builtin_ctz(mask);
		dp2[mask] += dp2[mask ^ (1 << x)] + t[x];
	}
	mark[(1 << k) - 1] = true;
	for (int mask = 0; mask < (1 << k); mask++) {
		if (dp[mask] + dp2[mask] <= e && !mark[mask | m0]) {
			ans++;
			mark[mask | m0] = true;
		}
	}
//	cout << ans << endl;
//	for (int i = 0; i < (1 << k); i++) {
//		cout << "73 " << i << " " << dp[i] << " " << dp2[i] << endl;
//	}
	cout << ans;
	return 0;
}