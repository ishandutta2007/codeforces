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
const int maxn = 550 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int dp[maxn][maxn], a[maxn], b[maxn], par[maxn];
vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > k)
			break;
		if (i == n)
			return cout << n << endl, 0;
		ans ++;
	}
	for (int i = n; i >= 1; i--) {
		if (a[i] > k)
			break;
		ans ++;
	}
	cout << ans << endl;
}