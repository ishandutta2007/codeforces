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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, m, k;
vector <pair<int, string> > ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	if (k > 4 * n * m - 2 * n - 2 * m)
	{
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	if (k <= m - 1)
		ans.push_back({ k, "R" });
	else
	{
		ans.push_back({ m - 1, "R" });
		k -= m - 1;
		if (k > 0)
		{
			if (k <= m - 1)
				ans.push_back({ k, "L" });
			else
			{
				ans.push_back({ m - 1, "L" });
				k -= m - 1;
				for (int i = 0; i < n - 1; i++)
				{
					if (k > 0)
					{
						ans.push_back({ 1, "D" });
						k--;
						if (k > 0)
						{
							if (k <= (m - 1) * 3)
							{
								if (k / 3 > 0)
								{
									ans.push_back({ k / 3, "RUD" });
									k %= 3;
								}
								if (k == 2)
									ans.push_back({ 1, "RU" });
								else if (k == 1)
									ans.push_back({ 1,"R" });

								k = 0;
								break;
							}
							else
							{
								ans.push_back({ m - 1, "RUD" });
								k -= (m - 1) * 3;
							}
						}
					}
					else break;

					if (k > 0)
					{
						if (k <= m - 1)
							ans.push_back({ k, "L" }), k = 0;
						else
							ans.push_back({ m - 1,"L" }), k -= m - 1;
					}
				}

				if (k > 0)
				{
					ans.push_back({ k, "U" });
				}
			}
		}
	}

	int del = 0;
	for (auto it : ans)
	{
		if (it.first == 0) del++;
	}

	cout << ans.size() - del << '\n';
	for (auto it : ans)
	{
		if (it.first == 0) continue;
		cout << it.first << ' ' << it.second << '\n';
	}
}