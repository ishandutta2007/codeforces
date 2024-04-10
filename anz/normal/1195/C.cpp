#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n;
ll student[2][100001];

ll memo[2][100001];
ll dp(int x, int y)
{
	ll& ret = memo[x][y];
	if (ret != -1) return ret;

	ret = student[x][y];

	ll tmp = 0;
	if (y < n - 1) tmp = max(tmp, dp(1 - x, y + 1));
	if (y < n - 2)
	{
		tmp = max(tmp, dp(1 - x, y + 2));
	}

	return ret += tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) cin >> student[i][j];

	memset(memo, -1, sizeof memo);

	ll ans = 0;
	for (int i = 0; i < 2; i++) for (int j = 0; j < min(n,2); j++)
		ans = max(ans, dp(i, j));

	cout << ans;
}