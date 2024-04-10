#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <deque>
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
const int maxn = 2e5 + 100;
const ll inf = 1e18;

ll dp[3][maxn];

int a[maxn], t[maxn];
int main() {
	ios_base::sync_with_stdio(false);
	ll n, m, d, ans = 0;
	cin >> n >> m >> d;
	for (int i = 1; i <= m; i++) {
		int b;
		cin >> a[i] >> b >> t[i];
		ans += b;
	}
	for (int i = 1; i <= n; i++)
		dp[1][i] = abs (a[1] - i);

	for (ll i = 2; i <= m; i++) {
		ll dis = d * (t[i] - t[i - 1]);
		int idx = i % 2, ptr = 1;
		deque <ll> deq;
		for (ll j = 1; j <= n; j++) {
			while (ptr <= min (j + dis, n)) {
				while (!deq.empty() and dp[idx^1][deq.back()] >= dp[idx^1][ptr]) {
					deq.pop_back();
				}
				deq.push_back (ptr ++);
			}
			if (deq.front() < j - dis)
				deq.pop_front();
			dp[idx][j] = dp[idx^1][deq.front()] + abs (j - a[i]);
		}
	}
	
	ll Mn = inf;
	for (int i = 1; i <= n; i++)
		Mn = min (Mn, dp[m%2][i]);
	cout << ans - Mn << endl;
}