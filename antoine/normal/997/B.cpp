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

const int MaxK = 40;
const int MaxS = MaxK * 50;

int dp[MaxK + 1][MaxS + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	dp[0][0] = 1;
	for (int k = 1; k <= MaxK; ++k)
		for (int x : {1, 5, 10, 50})
			for (int s = x; s <= MaxS; ++s)
				dp[k][s] |= dp[k - 1][s - x];

	int n;
	cin >> n;
	int k = min(n, MaxK);
	cout << accumulate(dp[k], dp[k] + MaxS + 1, 0) + 49LL * (n - k);

	return 0;
}