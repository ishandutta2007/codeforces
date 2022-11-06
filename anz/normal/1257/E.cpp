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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200010;

int n;
int who[N];
vector <int> dir[3];

int dp[N][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int k[3]; for (int i = 0; i < 3; i++) cin >> k[i];
	int n = k[0] + k[1] + k[2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < k[i]; j++)
		{
			int t; cin >> t;
			who[t] = i;
			dir[i].push_back(t);
		}
	}

	for (int i = 0; i < 3; i++) if (who[1] != i) dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + (who[i] == 0 ? 0 : 1);
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (who[i] == 1 ? 0 : 1);
		dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + (who[i] == 2 ? 0 : 1);
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}