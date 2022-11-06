#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n, m;
char board[501][501];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", board[i]);
	}

	int x = -1, y = -1;
	bool flag = false;
	for (int i = 1; i < n - 1; i++)
	{
		if (x != -1 && y != -1 && !flag) break;
		for (int j = 1; j < m - 1; j++)
		{
			if (board[i][j] == '*')
			{
				if (board[i - 1][j] == '*' && board[i + 1][j] == '*' && board[i][j - 1] == '*' && board[i][j + 1] == '*')
				{
					if (!flag)
					{
						x = i, y = j;
						flag = true;
					}
					else
					{
						flag = false;
						break;
					}
				}
			}
		}
	}

	if (flag)
	{
		board[x][y] = '.';

		int cx = x - 1, cy = y;
		while (cx >= 0)
		{
			if (board[cx][cy] != '*') break;
			board[cx][cy] = '.';
			cx--;
		}

		cx = x + 1, cy = y;
		while (cx < n)
		{
			if (board[cx][cy] != '*') break;
			board[cx][cy] = '.';
			cx++;
		}

		cx = x, cy = y - 1;
		while (cy >= 0)
		{
			if (board[cx][cy] != '*') break;
			board[cx][cy] = '.';
			cy--;
		}

		cx = x, cy = y + 1;
		while (cy < m)
		{
			if (board[cx][cy] != '*') break;
			board[cx][cy] = '.';
			cy++;
		}

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			if (board[i][j] == '*') flag = false;
	}

	if (flag) printf("YES");
	else printf("NO");
}