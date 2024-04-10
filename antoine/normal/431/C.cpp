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

int K, D;
const int mod = (int)1e9 + 7;

int dp[101][2];

int f(int n, bool b) {
	if (!n) return b;
	int &ans = dp[n][b];
	if (ans != -1)
		return ans;
	ans = 0;
	for (int i = 1; i <= min(K, n); ++i)
		ans = (ans + f(n - i, b || i >= D)) % mod;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof dp);
	int n;
	cin >> n >> K >> D;
	cout << f(n, 0);
	return 0;
}