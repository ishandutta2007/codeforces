#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:1024000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int gcd(int a, int b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

bitset<700> dp[700];
int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<bitset<700>> g(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			g[i][j] = gcd(a[i], a[j]) > 1;
	for (int i = 0; i < n; ++i)
		dp[i][i] = 1;
	for (int len = 2; len <= n; ++len)
		for (int i = 0; i < n; ++i) {
			if (i + 1 >= len) {
				int j = i - len + 1;
				bool t = 0;
				for (int k = j; k < i; ++k)
					if (g[i][k] & dp[k][j] & dp[k][i - 1]) {
						t = 1; break;
					}
				if (t) dp[i][j] = 1;
			}
			if (i + len <= n) {
				int j = i + len - 1;
				bool t = 0;
				for (int k = i + 1; k <= j; ++k)
					if (g[i][k] & dp[k][j] & dp[k][i + 1]) {
						t = 1; break;
					}
				if (t) dp[i][j] = 1;
			}
		}
	bool ans = 0;
	for (int i = 0; i < n; ++i)
		if (dp[i][0] & dp[i][n - 1]) {
			ans = 1; break;
		}
	if (ans) cout << "Yes";
	else cout << "No";
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}