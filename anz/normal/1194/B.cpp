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

int n, m;
string board[50001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> board[i];
		int maxRow = 0, maxCol = 0;
		set <int> rows, cols;

		for (int i = 0; i < n; i++)
		{
			int tmpSum = 0;
			for (int j = 0; j < m; j++)
				if (board[i][j] == '*') tmpSum++;

			if (tmpSum > maxRow)
			{
				maxRow = tmpSum;
				rows.clear();
				rows.insert(i);
			}
			else if (tmpSum == maxRow)
				rows.insert(i);
		}

		for (int j = 0; j < m; j++)
		{
			int tmpSum = 0;
			for (int i = 0; i < n; i++)
				if (board[i][j] == '*') tmpSum++;

			if (tmpSum > maxCol)
			{
				maxCol = tmpSum;
				cols.clear();
				cols.insert(j);
			}
			else if (tmpSum == maxCol)
				cols.insert(j);
		}

		int ans = n - maxRow + m - maxCol;

		bool flag = false;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '.')
			{
				if (rows.find(i) != rows.end() && cols.find(j) != cols.end())
					flag = true;
			}
		}

		if (flag) ans--;
		cout << ans << "\n";
	}
}