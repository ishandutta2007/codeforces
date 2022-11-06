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

int mp[100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll n, m; cin >> n >> m;
		ll sum = 0;
		for (int i = 0; i < 100; i++) mp[i] = 0;
		for (int i = 0; i < m; i++)
		{
			ll a; cin >> a;
			sum += a;
			int cnt = 0;
			while (a > 1) a /= 2, cnt++;
			mp[cnt]++;
		}

		if (n > sum)
		{
			cout << "-1\n";
			continue;
		}

		ll ans = 0;
		for (int i = 0; i <= 60; i++)
		{
			if (n & (1ll << i))
			{
				if (mp[i])
				{
					mp[i + 1] += (mp[i] - 1) / 2;
					continue;
				}

				mp[i] += 2;
				for (int j = i + 1; j <= 60; j++)
				{
					if (mp[j])
					{
						mp[j]--;
						ans += j - i;
						break;
					}
					else mp[j] += 1;
				}
			}
			else mp[i + 1] += mp[i] / 2;
		}
		
		cout << ans << '\n'; 
	}
}