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
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>
#include <ctime>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
pii board[1001][1001];
int ans[1001][1001];
// X : 0, U : 1, D : 2, L : 3, R : 4

int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,1,-1 };

bool isValid(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(ans, -1, sizeof ans);

	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> board[i][j].first >> board[i][j].second;

	queue <pii> q;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		if (board[i][j].first == i && board[i][j].second == j)
		{
			ans[i][j] = 0;
			q.push({ i,j });
		}
	}

	while (!q.empty())
	{
		pii cur = q.front(); q.pop();
		int x = cur.first, y = cur.second;

		for (int k = 1; k <= 4; k++)
		{
			int cx = x + dx[k], cy = y + dy[k];
			if (!isValid(cx, cy)) continue;
			if (ans[cx][cy] != -1) continue;
			if (board[cx][cy] != board[x][y]) continue;

			ans[cx][cy] = k;
			q.push({ cx,cy });
		}
	}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		if (ans[i][j] == -1 && board[i][j] == pii(-1, -1))
		{
			int x = i, y = j;
			for (int k = 1; k <= 4; k++)
			{
				int cx = x + dx[k], cy = y + dy[k];
				if (!isValid(cx, cy)) continue;
				if (ans[cx][cy] != -1) continue;
				if (board[cx][cy] != board[x][y]) continue;

				q.push({ cx,cy });
				q.push({ x,y });
				ans[cx][cy] = k;
				if (k == 1) ans[x][y] = 2;
				else if (k == 2) ans[x][y] = 1;
				else if (k == 3) ans[x][y] = 4;
				else if (k == 4) ans[x][y] = 3;

				while (!q.empty())
				{
					pii cur = q.front(); q.pop();
					int x = cur.first, y = cur.second;

					for (int k = 1; k <= 4; k++)
					{
						int cx = x + dx[k], cy = y + dy[k];
						if (!isValid(cx, cy)) continue;
						if (ans[cx][cy] != -1) continue;
						if (board[cx][cy] != board[x][y]) continue;

						ans[cx][cy] = k;
						q.push({ cx,cy });
					}
				}
				break;
			}
		}
	}

	bool isValid = true;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		if (ans[i][j] == -1) isValid = false;
	}

	if (!isValid)
	{
		cout << "INVALID";
		return 0;
	}

	cout << "VALID\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			switch (ans[i][j])
			{
			case 0:
				cout << "X";
				break;
			case 1:
				cout << "U";
				break;
			case 2:
				cout << "D";
				break;
			case 3:
				cout << "L";
				break;
			case 4:
				cout << "R";
				break;
			}
		}
		cout << '\n';
	}
}