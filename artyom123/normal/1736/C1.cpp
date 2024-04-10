#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <random>
#include <ctime>
#include <string_view>
 
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define ld long double
#define pb emplace_back
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define mp make_pair
 
const int INF = 1e9 + 10;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = a[i] - i - 1;
	}
	vector<vector<int>> dp(n, vector<int>(2));
	vector<int> id(n, -1);
	int r = 0;
	ll ans = 0;
	ll sum_l = 0;
	for (int l = 0; l < n; l++) {
		if (r < l) r = l;
		while (r + 1 < n && a[r + 1] + l >= 0) r++;
		dp[l][0] = r;
		ans += r;
		sum_l += l - 1;
	}
	r = 0;
	int bad_id = -1;
	for (int l = 0; l < n; l++) {
		if (r < l) r = l;
		if (bad_id != -1) {
			if (a[bad_id] + l >= 0) bad_id = -1;
		}
		while (r + 1 < n) {
			if (a[r + 1] + l >= 0) r++;
			else if (bad_id == -1) bad_id = ++r;
			else break;
		}
		id[l] = bad_id;
		dp[l][1] = r;
	}
	cout << ans - sum_l << "\n";
}

int main()
{
	#ifdef LOCAL
		freopen("input", "r", stdin);
		freopen("output", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}