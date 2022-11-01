#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)((a).size())
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int M = 998244353;
const int N = 1001;
const int A = 100001;

int n, k;
int a[N];
int dp[N][N];
int ans[A];
int ANS;
int pt[N];

int add(int x, int y) {
	x += y;
	if (x >= M) {
		x -= M;
	}
	return x;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	memset(pt, -1, sizeof(pt));
	for (int i = 0; i < N; i++) {
		dp[i][0] = 1;
	}
	dp[0][1] = 1;
	for (int x = A / (k - 1); x >= 0; x--) {
		for (int i = 0; i < n; i++) {
			while (pt[i] + 1 < i && a[i] - a[pt[i] + 1] >= x) {
				pt[i]++;
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= k; j++) {
				dp[i][j] = add(dp[i - 1][j], (pt[i] == -1 ? (j == 1) : dp[pt[i]][j - 1]));
			}
		}
		ans[x] = dp[n - 1][k];
		//if(ans[x]) cout << x << ' ' << ans[x] << endl;
	}
	for (int x = A - 1; x >= 0; x--) {
		ANS = add(ANS, 1LL * x * ((ans[x] - (x == A - 1 ? 0 : ans[x + 1]) + M) % M) % M);
	}
	cout << ANS;
}