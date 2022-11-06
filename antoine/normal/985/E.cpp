#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

struct DS {
	int cnt[2];
	DS() {
		memset(cnt, 0, sizeof cnt);
	}
	void insert(bool x) {
		++cnt[x];
	}
	void erase(bool x) {
		--cnt[x];
	}
	bool lor() {
		return cnt[0] >= 0 && cnt[1] > 0;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, d;
	cin >> n >> k >> d;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());

	vector<bool> dp(n + 1, false);
	DS ds;
	dp[n] = 1;

	for (int i = n - k, j = n; i >= 0; --i) {
		ds.insert(dp[i + k]);
		while (a[j - 1] - a[i] > d)
			ds.erase(dp[j--]);
	
		dp[i] = ds.lor();
	}


	cout << (dp[0] ? "YES" : "NO");
	return 0;
}