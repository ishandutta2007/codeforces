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
typedef unsigned long long ull;
const int maxn = 1e4 + 100;
const ll inf = 1e18;

ll p[maxn], s[maxn], dp[3][maxn];
bool mark[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	
	// Shame On me !!!
	
	ll n, c;
	cin >> n >> c;
	for (ll i = 1; i <= n; i++)
		cin >> p[i];
	for (ll i = 1; i <= n; i++)
		cin >> s[i];
	ll ans = inf;
	memset (dp, 31, sizeof dp);
	dp[0][0] = 0;
	for (ll i = 1; i <= n; i++) {
		bool q = i % 2;
		dp[q][0] = dp[q ^ 1][0] + p[i];
		for (ll j = 1; j <= i; j++) {
			dp[q][j] = min (dp[q ^ 1][j - 1] + s[i], dp[q ^ 1][j] + p[i] + j * c);
			if (i == n)
				ans = min (ans, dp[q][j]);
		}
	}
	cout << min (ans, dp[n % 2][0]) << endl;
}