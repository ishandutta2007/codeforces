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

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int n;
int a[700];
int adj[700][700];
int dp[700][700][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			adj[i][j] = adj[j][i] = gcd(a[i], a[j]) > 1;

	for (int i = 0; i < n; ++i)
		for (int b = 0; b < 2; ++b)
			dp[i][i][b] = 1;

	for (int diff = 1; diff < n; ++diff)
		for (int j = diff; j < n; ++j)
			for (int b = 0; b < 2; ++b) {
				const int i = j - diff;
				const int root = b ? j : i;
				const int left = b ? i : i + 1;
				const int right = b ? j - 1 : j;

				for (int k = left; k <= right; ++k)
					if (adj[root][k] && dp[left][k][1] && dp[k][right][0]) {
						dp[i][j][b] = true;
						break;
					}
			}
	for(int i = 0; i < n; ++i)
		if (dp[0][i][1] && dp[i][n - 1][0]) {
			cout << "Yes\n";
			return 0;
		}
	cout << "No\n";
	return 0;
}