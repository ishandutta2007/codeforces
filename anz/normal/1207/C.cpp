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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

ll n, a, b;
string road;
int haveToLift[200010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> a >> b;
		cin >> road;
		for (int i = 0; i <= n; i++) haveToLift[i] = 0;


		for (int i = 0; i < n; i++)
		{
			if (road[i] == '1')
			{
				haveToLift[i] = 1;
				haveToLift[i + 1] = 1;
			}
		}

		ll ans = a * n + b * (n + 1);

		int curHeight = 1;
		ll curWidth = 0;
		bool isFirst = true;

		for (int i = 1; i < n; i++)
		{
			if (curHeight == 1)
			{
				if (haveToLift[i] == 0)
				{
					curWidth++;
					continue;
				}
					
				if (!isFirst)
				{
					if (curWidth * b > 2 * a)
					{
						ans += 2 * a + b;
					}
					else
					{
						ans += curWidth * b + b;
					}
				}
				else
				{
					isFirst = false;
					ans += a + b;
				}

				curWidth = 0;
				curHeight = 2;
			}
			else
			{
				if (haveToLift[i] == 1)
				{
					ans += b;
					continue;
				}

				curHeight = 1;
				curWidth++;
			}
		}

		if (!isFirst)
			ans += a;

		cout << ans << "\n";
	}
}