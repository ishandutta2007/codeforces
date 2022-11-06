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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int r, c;
string board[61];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++) cin >> board[i];

		int sum = 0;
		int row[60] = { 0, };
		int col[60] = { 0, };
		for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'A')
			{
				sum++;
				row[i]++, col[j]++;
			}
		}

		if (!sum)
		{
			cout << "MORTAL\n";
			continue;
		}
		if (sum == r*c)
		{
			cout << "0\n";
			continue;
		}


		if (row[0] == c || row[r - 1] == c || col[0] == r || col[c - 1] == r)
		{
			cout << "1\n";
			continue;
		}

		bool flag = false;
		for (int i = 1; i < r - 1; i++)
		{
			if (row[i] == c)
			{
				cout << "2\n";
				flag = true;
				break;
			}
		}
		if (flag) continue;

		for (int i = 1; i < c - 1; i++)
		{
			if (col[i] == r)
			{
				cout << "2\n";
				flag = true;
				break;
			}
		}
		if (flag) continue;

		if (board[0][0] == 'A' || board[r - 1][0] == 'A' || board[0][c - 1] == 'A' || board[r - 1][c - 1] == 'A')
		{
			cout << "2\n";
			continue;
		}

		for (int i = 1; i < r-1; i++)
		{
			if (board[i][0] == 'A' || board[i][c - 1] == 'A')
			{
				cout << "3\n";
				flag = true;
				break;
			}
		}
		if (flag) continue;

		for (int i = 1; i < c - 1; i++)
		{
			if (board[0][i] == 'A' || board[r - 1][i] == 'A')
			{
				cout << "3\n";
				flag = true;
				break;
			}
		}
		if (flag) continue;

		cout << "4\n";
	}
}