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

bool comp(pair<string, int> a, pair<string, int> b)
{
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;

		set <string> s;
		pair<string,int> pin[11];
		for (int i = 0; i < n; i++)
		{
			cin >> pin[i].first;
			pin[i].second = i;
			s.insert(pin[i].first);
		}

		int ans = 0;
		sort(pin, pin + n);
		for (int i = 0; i < n - 1; i++)
		{
			if (pin[i].first != pin[i + 1].first) continue;

			bool flag = false;
			for (int dig = 0; dig < 4; dig++)
			{
				for (int k = 0; k < 9; k++)
				{
					string newPin = pin[i].first;
					newPin[dig] = k + '0';

					if (s.find(newPin) == s.end())
					{
						ans++;
						pin[i].first = newPin;
						s.insert(newPin);

						flag = true;
						break;
					}
				}
				if (flag) break;
			}
		}

		sort(pin, pin + n, comp);

		cout << ans << '\n';
		for (int i = 0; i < n; i++)
			cout << pin[i].first << '\n';
	}
}