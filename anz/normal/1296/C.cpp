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

int n;
string s;
map <pii, int> mp;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> s;
		mp.clear();

		int ans = 987654321;
		int l = -1, r = -1;

		int x = 0, y = 0;
		mp[{x, y}] = 0;

		for (int i = 0; i < n; i++)
		{
			switch (s[i])
			{
			case 'L':
				x--;
				break;
			case 'R':
				x++;
				break;
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
			}

			if (mp.count({ x,y }))
			{
				int res = i - mp[{x, y}];
				if (ans > res)
				{
					ans = res;
					l = mp[{x, y}] + 1, r = i + 1;
				}
			}

			mp[{x, y}] = i + 1;
		}

		if (ans == 987654321)
		{
			cout << "-1\n";
			continue;
		}

		cout << l << ' ' << r << '\n';
	}
}