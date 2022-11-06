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

string s[2];
int dp[100][2][2];

int f(int i, int a, int b) {
	//cout << i << ' ' << a << ' ' << b << '\n';
	if (i >= s[0].size() - 1)
		return 0;
	int &ans = dp[i][a][b];
	if (ans != -1)
		return ans;
	ans = f(i+1, 0, 0);
	if (!a && !b && s[0][i] == '0' && s[1][i] == '0' && s[0][i+1] == '0')
		ans = max(ans, 1 + f(i + 1, 1, 0));
	if (!a && !b && s[0][i] == '0' && s[1][i] == '0' && s[1][i+1] == '0')
		ans = max(ans, 1 + f(i + 1, 0, 1));
	if (!a && s[0][i] == '0' && s[0][i+1] == '0' && s[1][i+1] == '0')
		ans = max(ans, 1 + f(i + 1, 1, 1));
	if (!b && s[1][i] == '0' && s[0][i+1] == '0' && s[1][i+1] == '0')
		ans = max(ans, 1 + f(i + 1, 1, 1));
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof dp);
	cin >> s[0] >> s[1];
	cout << f(0, 0, 0);
	return 0;
}