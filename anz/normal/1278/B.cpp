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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll a, b; cin >> a >> b;
		ll d = a - b; if (d < 0) d = -d;
		for (ll i = 0;; i++)
		{
			if ((i + 1) / 2 % 2 == 0)
			{
				if (d % 2 == 0 && d <= i*(i + 1) / 2)
				{
					cout << i << '\n';
					break;
				}
			}
			else
			{
				if (d % 2 == 1 && d <= i*(i + 1) / 2)
				{
					cout << i << '\n';
					break;
				}
			}
		}
	}
}