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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int k;
int dp[256];

int f(int i) {
	assert(i >= 0 && i < 256);
	if (dp[i] != -1) return dp[i];
	int lo = i, hi = i;
	while (lo > 0) {
		if (dp[lo - 1] == -1 && hi - lo + 1 < k)
			lo--;
		else if ((hi - lo + 1) + ((lo - 1) - dp[lo - 1] + 1) > k)
			break;
		else
			lo = dp[lo - 1];
	}
	while (hi != lo)
		dp[hi--] = lo;
	return dp[lo] = lo;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof dp);

	int n;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		cout << f(a) << ' ';
	}
	return 0;
}