#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
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
const int maxn = 2e5 + 50;
const int Maxn = 5e3 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
string a, b;
int n, dp[200];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	n = a.size();
	a = " " + a;
	b = " " + b;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (a[i] == '0' and b[i] == '0' and (a[i - 1] == '0' or b[i - 1] == '0'))
			dp[i] = max (dp[i], dp[i - 2] + 1);
		if (i >= 3 and a[i] == '0' and b[i] == '0' and a[i - 1] == '0' and b[i - 1] == '0' and a[i - 2] == '0' and b[i - 2] == '0')
			dp[i] = max (dp[i], dp[i - 3] + 2);
		if ((a[i] == '0' or b[i] == '0') and a[i - 1] == '0' and b[i - 1] == '0')
			dp[i] = max (dp[i], dp[i - 2] + 1);
	}
	cout << dp[n] << endl;
}