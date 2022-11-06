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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll n, m, a, b;
ll g, x, y, z;

ll board[3001][3001];

ll minVal[3001][3001];

int main()
{
	cin >> n >> m >> a >> b;
	cin >> g >> x >> y >> z;
	board[0][0] = g;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (i == 0 && j == 0) continue;
		g = g * x + y;
		g %= z;
		board[i][j] = g;
	}

	for (int i = 0; i < n; i++)
	{
		deque <pii> q;
		q.push_back({ board[i][0], 0 });
		minVal[i][0] = board[i][0];
		for (int j = 1; j < m; j++)
		{
			if (q.front().second <= j - b) q.pop_front();
			while (!q.empty() && q.back().first > board[i][j]) q.pop_back();
			q.push_back({ board[i][j],j });

			minVal[i][j] = q.front().first;
		}
	}

	ll ans = 0;

	for (int i = b - 1; i < m; i++)
	{
		deque <pii> q;
		q.push_back({ minVal[0][i], 0 });
		if (a == 1) ans += minVal[0][i];
		for (int j = 1; j < n; j++)
		{
			if (q.front().second <= j - a) q.pop_front();
			while (!q.empty() && q.back().first > minVal[j][i]) q.pop_back();
			q.push_back({ minVal[j][i], j });

			if (j >= a - 1)
				ans += q.front().first;
		}
	}

	cout << ans;
}