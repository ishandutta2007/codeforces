#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 4e3 + 100;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int dp[maxn][maxn], c[maxn], r[maxn];
vector <pair <pair <int, int>, pair <int, int> > > v;
bool nex[maxn][maxn];
pair <int, int> rig[maxn];

void dfs (int l, int r) {
	if (r - l < 1)
		return;
	if (nex[l][r] == 0)
		dfs (l + 1, r);
	else {
		cout << rig[l].S << " ";
		dfs (l + 1, rig[l].F);
		dfs (rig[l].F, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i] >> r[i];
		v.PB ({{c[i] - r[i], +1}, {-(c[i] + r[i]), i}});
		v.PB ({{c[i] + r[i], -1}, {-(c[i] - r[i]), i}});
	}
	sort (v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		int l = lower_bound (v.begin(), v.end(), MP (MP (c[i] - r[i], +1), MP (-(c[i] + r[i]), i))) - v.begin() + 1;
		rig[l].F = lower_bound (v.begin(), v.end(), MP (MP (c[i] + r[i], -1), MP (-(c[i] - r[i]), i))) - v.begin() + 1;	
		rig[l].S = i;
	}
	for (int len = 1; len < 2 * n; len++) {
		for (int i = 1; i <= 2 * n - len; i++) {
			int j = i + len;
			dp[i][j] = dp[i + 1][j];
			if (rig[i].F <= j and rig[i].F > 0 and dp[i][j] < dp[i + 1][rig[i].F] + dp[rig[i].F][j] + 1) {
				dp[i][j] = dp[i + 1][rig[i].F] + dp[rig[i].F][j] + 1;
				nex[i][j] = 1;
			}
		}
	}
	cout << dp[1][2 * n] << endl;
	dfs (1, 2 * n);
}