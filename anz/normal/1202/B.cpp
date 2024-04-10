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

int dp[10][10][10][10]; //i- j counter make a to b

ll ans[10][10];
bool canMake[10][10];

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++)
	{
		for (int a = 0; a < 10; a++)
		{
			int isSearched[10];
			memset(isSearched, -1, sizeof isSearched);

			queue <int> q; q.push(a);
			while (!q.empty())
			{
				int curNum = q.front(); q.pop();

				int nextNum = (curNum + i) % 10;
				if (isSearched[nextNum] == -1)
				{
					if (curNum == a) isSearched[nextNum] = 1;
					else isSearched[nextNum] = isSearched[curNum] + 1;
					q.push(nextNum);
				}

				nextNum = (curNum + j) % 10;
				if (isSearched[nextNum] == -1)
				{
					if (curNum == a) isSearched[nextNum] = 1;
					else isSearched[nextNum] = isSearched[curNum] + 1;
					q.push(nextNum);
				}
			}

			for (int b = 0; b < 10; b++)
				dp[i][j][a][b] = isSearched[b];
		}
	}

	cin >> s;
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) canMake[i][j] = true;

	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < s.size() - 1; k++)
		{
			int i_counter = dp[i][j][s[k] - '0'][s[k + 1] - '0'];
			if (i_counter == -1) canMake[i][j] = false;
			else ans[i][j] += i_counter-1;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (!canMake[i][j]) cout << "-1 ";
			else cout << ans[i][j] << ' ';
		}
		cout << "\n";
	}
}