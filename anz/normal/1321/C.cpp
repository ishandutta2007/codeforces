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
list <char> ls;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> s;
	for (char c : s) ls.push_back(c);

	int ans = 0;
	for (char c = 'z'; c >= 'b'; c--)
	{
		for (int i = 0; i < 100; i++)
		{
			for (auto it = ls.begin(); it != ls.end();)
			{
				if (*it == c)
				{
					if (it != ls.begin() && *prev(it) == c - 1 ||
						next(it) != ls.end() && *next(it) == c - 1)
					{
						ans++;
						auto jt = next(it);
						ls.erase(it);
						it = jt;
					}
					else it++;
				}
				else it++;
			}
		}
	}

	cout << ans;
}