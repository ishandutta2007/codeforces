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

const int mod = (int) 1e9 + 7;
const int MaxN = (int) 1e5 + 9;
ll dp[MaxN + 9][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;
	const int n = (int) s.size();


dp[n][0] = dp[n][1] = 1;

	for (int i = n - 1; i >= 0; --i) {
		dp[i][0] = (dp[i + 1][0] + (s[i] == 'a' ? dp[i + 1][1] : 0)) % mod;
		dp[i][1] = dp[i+1][s[i] != 'b'];
	}
	cout << (dp[0][0] + mod - 1) % mod << endl;
	return 0;
}