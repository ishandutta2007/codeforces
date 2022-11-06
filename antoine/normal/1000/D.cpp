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

const int mod = 998244353;
int a[(int)1e3];
int dp[(int)1e3 + 1][(int)1e3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	for(int i = n; i >= 0; --i)
		for (int j = 0; j < n; ++j) {
			int &res = dp[i][j];
			if (i == n)
				res = !j;
			else {
				res = dp[i + 1][j];
				if (j > 0)
					res += dp[i + 1][j - 1];
				else if (a[i] > 0 && a[i] < n)
					res += dp[i + 1][a[i]];
				res %= mod;
			}
		}
	cout << (dp[0][0] + mod - 1) % mod;
	return 0;
}