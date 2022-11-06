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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int q; cin >> q;
	while (q--)
	{
		ll n; cin >> n;
		vector <ll> d;
		while (n)
		{
			d.push_back(n % 3);
			n /= 3;
		}

		int l2 = -1;
		for (int i = 0; i < d.size(); i++)
		{
			if (d[i] == 2)
			{
				l2 = i;
			}
		}
		
		for (int i = 0; i < d.size(); i++)
		{
			if (i < l2) d[i] = 0;
			else
			{
				if (d[i] == 2)
				{
					d[i] = 0;
					if (i != d.size() - 1) d[i + 1]++;
					else d.push_back(1);
				}
			}
		}

		ll ans = 0;
		ll t = 1;
		for (int i = 0; i < d.size(); i++)
		{
			ans += d[i] * t;
			t *= 3;
		}
		cout << ans << "\n";
	}
}