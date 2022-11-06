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

const ll MOD = 1e9 + 7;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	//freopen("input.txt", "r", stdin);
	int t; cin >> t;
	while (t--)
	{
		int x; string s;
		cin >> x >> s;

		ll len = s.size();
		ll cursor = 0;

		bool flag = false;
		while (cursor != x)
		{
			if (cursor == 38661)
			{
				int stop_here = 0;
			}
			cursor++;
			ll copy = len - cursor;
			if (copy < 0) copy += MOD;
			if (flag) copy %= MOD;
			ll times = (s[cursor - 1] - '0');

			string tmp;
			for (int i = 0; i < times - 1; i++)
			{
				if (!flag)
				{
					tmp += s.substr(cursor);
				}
				len += copy;
				if (len >= x) flag = true;
				if (flag) len %= MOD;
			}
			s += tmp;
		}
		cout << len << '\n';
	}
}