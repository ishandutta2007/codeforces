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

int r, c, k;
char board[101][101];
int res[101][101];

char ans[100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 26; i++) ans[i] = 'a' + i;
	for (int i = 0; i < 26; i++) ans[i + 26] = 'A' + i;
	for (int i = 0; i < 10; i++) ans[i + 52] = '0' + i;

	int T; cin >> T;
	while (T--)
	{
		cin >> r >> c >> k;

		int rice = 0;
		for (int i = 0; i < r; i++)
		{
			cin >> board[i];
			for (int j = 0; j < c; j++)
			{
				if (board[i][j] == 'R') rice++;
			}
		}

		int rpc = rice / k;
		int remain = rice - rpc * k;

		int cc = 0;
		int curRice = 0;
		for (int i = 0; i < r; i++)
		{
			if (i % 2 == 0)
			{
				for (int j = 0; j < c; j++)
				{
					res[i][j] = cc;
					if (board[i][j] == 'R')
					{
						curRice++;
						if (remain > 0 && curRice == rpc + 1 ||
							remain == 0 && curRice == rpc)
						{
							if (cc != k - 1)
								cc++;
							curRice = 0;
							if (remain > 0)
								remain--;
						}
					}
				}
			}
			else
			{
				for (int j = c - 1; j >= 0; j--)
				{
					res[i][j] = cc;
					if (board[i][j] == 'R')
					{
						curRice++;
						if (remain > 0 && curRice == rpc + 1 ||
							remain == 0 && curRice == rpc)
						{
							if (cc != k - 1)
								cc++;
							curRice = 0;
							if (remain > 0)
								remain--;
						}
					}
				}
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
				cout << ans[res[i][j]];
			cout << '\n';
		}
	}
}