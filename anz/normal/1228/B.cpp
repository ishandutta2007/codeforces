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

int h, w;
int board[1010][1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	memset(board, -1, sizeof board);
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		int n; cin >> n;
		for (int j = 0; j < n; j++) board[i][j] = 1;
		board[i][n] = 0;
	}

	bool flag = true;
	for (int i = 0; i < w; i++)
	{
		int n; cin >> n;
		for (int j = 0; j < n; j++)
		{
			if (board[j][i] == 0)
			{
				flag = false;
			}
			board[j][i] = 1;
		}

		if (board[n][i] == 1)
			flag = false;

		board[n][i] = 0;
	}

	if (!flag)
	{
		cout << 0;
		return 0;
	}

	ll ans = 1;
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
	{
		if (board[i][j] == -1)
		{
			ans *= 2;
			ans %= 1000000007;
		}
	}
	cout << ans;
}