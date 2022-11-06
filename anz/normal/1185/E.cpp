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

char board[2001][2001];
vector <pii> al[26];
int lastAl;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 26; i++) al[i].clear();
		lastAl = -1;
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", &board[i]);

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			if (board[i][j] != '.')
			{
				al[board[i][j] - 'a'].push_back({ i,j });
				lastAl = max(lastAl, board[i][j] - 'a');
			}
		}

		vector <pair<pii, pii> > ans;
		bool flag = true;
		for (int i = lastAl; i >= 0; i--)
		{
			vector <pii> tmp = al[i];

			if (tmp.empty())
			{
				ans.push_back(ans.back());
				continue;
			}

			//sort(tmp.begin(), tmp.end());

			if (tmp.front().first == tmp.back().first)
			{
				for (int j = 1; j < tmp.size(); j++)
				{
					if (tmp[j].first != tmp[j - 1].first)
					{
						flag = false;
						break;
					}
				}

				for (int j = tmp.front().second; j <= tmp.back().second; j++)
				{
					if (board[tmp.front().first][j] != 'a' + i &&
						board[tmp.front().first][j] != '?')
					{
						flag = false;
						break;
					}
					board[tmp.front().first][j] = '?';
				}

				if (flag)
				{
					ans.push_back({ {tmp.front().first,tmp.front().second},{tmp.back().first,tmp.back().second} });
				}
			}
			else if (tmp.front().second == tmp.back().second)
			{
				for (int j = 1; j < tmp.size(); j++)
				{
					if (tmp[j].second != tmp[j - 1].second)
					{
						flag = false;
						break;
					}
				}

				for (int j = tmp.front().first; j <= tmp.back().first; j++)
				{
					if (board[j][tmp.front().second] != 'a' + i &&
						board[j][tmp.front().second] != '?')
					{
						flag = false;
						break;
					}
					board[j][tmp.front().second] = '?';
				}

				if (flag)
				{
					ans.push_back({ { tmp.front().first,tmp.front().second },{ tmp.back().first,tmp.back().second } });
				}
			}
			else
			{
				flag = false;
				break;
			}

			if (flag == false) break;
		}

		if (flag)
		{
			reverse(ans.begin(), ans.end());
			printf("YES\n");
			printf("%d\n", ans.size());
			for (int i = 0; i < ans.size(); i++)
				printf("%d %d %d %d\n", ans[i].first.first + 1, ans[i].first.second + 1,
					ans[i].second.first + 1, ans[i].second.second + 1);
		}
		else
			printf("NO\n");
	}
}