#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
const int Maxn = 1e5 + 1;
const int mod = 1e9 + 7;
const int block = 333;
int a[maxn], par[maxn], dp[maxn];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		par[i] = par[i - 1] + a[i];
		dp[i] = min (dp[i - 1], par[i]);
		ans += a[i];
	}
	
	int fi = ans;
	ans = ans + -2 * dp[n];
	int tmp = 0;
	for (int i = n; i >= 1; i--) {
		tmp += a[i];
		ans = max (ans, fi + -2 * (tmp + dp[i - 1]));
	}
	cout << ans << endl;
}