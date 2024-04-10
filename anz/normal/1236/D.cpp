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

int n, m, k;
set <int> ox[100001];
set <int> oy[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;

	int fillLeft = 0, fillRight = m + 1;
	int fillUp = 0, fillDown = n + 1;

	for (int i = 0; i < k; i++)
	{
		int x, y; cin >> x >> y;
		ox[x].insert(y);
		oy[y].insert(x);
	}

	int curD = 0;
	bool ans = true;
	while (fillLeft + 1 < fillRight && fillUp + 1 < fillDown)
	{
		if (curD == 0)
		{
			while (ox[fillUp + 1].size())
			{
				int tmp = *ox[fillUp + 1].rbegin();
				if (tmp != fillRight - 1 || oy[tmp].size() != fillDown - fillUp - 1)
				{
					ans = false;
					break;
				}

				for (auto i : oy[tmp])
				{
					ox[i].erase(tmp);
				}
				oy[tmp].clear();

				fillRight--;
			}
			fillUp++;
		}
		else if (curD == 1)
		{
			while (oy[fillRight - 1].size())
			{
				int tmp = *oy[fillRight - 1].rbegin();
				if (tmp != fillDown - 1 || ox[tmp].size() != fillRight - fillLeft - 1)
				{
					ans = false;
					break;
				}

				for (auto i : ox[tmp])
				{
					oy[i].erase(tmp);
				}
				ox[tmp].clear();

				fillDown--;
			}
			fillRight--;
		}
		else if (curD == 2)
		{
			while (ox[fillDown - 1].size())
			{
				int tmp = *ox[fillDown - 1].begin();
				if (tmp != fillLeft + 1 || oy[tmp].size() != fillDown - fillUp - 1)
				{
					ans = false;
					break;
				}

				for (auto i : oy[tmp])
				{
					ox[i].erase(tmp);
				}
				oy[tmp].clear();

				fillLeft++;
			}
			fillDown--;
		}
		else if (curD == 3)
		{
			while (oy[fillLeft + 1].size())
			{
				int tmp = *oy[fillLeft + 1].begin();
				if (tmp != fillUp + 1 || ox[tmp].size() != fillRight - fillLeft - 1)
				{
					ans = false;
					break;
				}

				for (auto i : ox[tmp])
				{
					oy[i].erase(tmp);
				}
				ox[tmp].clear();

				fillUp++;
			}
			fillLeft++;
		}

		curD = (curD + 1) % 4;
	}

	if (ans) cout << "Yes";
	else cout << "No";
}