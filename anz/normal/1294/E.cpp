#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	vector<vector<int> > board(n, vector<int>(m));
	for (auto&it : board) for (auto&jt : it) cin >> jt;

	ll ans = 0;
	for (int j = 0; j < m; j++)
	{
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			if (board[i][j] % m != (j + 1) % m) continue;
			if (board[i][j] > n*m) continue;
			int orgin = m * i + j + 1;
			int dif = orgin - board[i][j];
			if (dif < 0) dif += n * m;
			dif /= m;
			mp[dif]++;
		}

		int minVal = n;
		for (auto&it : mp)
		{
			minVal = min(minVal, it.first + n - it.second);
		}

		ans += minVal;
	}
	cout << ans;
}