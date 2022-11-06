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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll n, m, k;
ll a[300001];

ll subSum[300001];

ll subSum_K[300001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i + 1];
		subSum[i + 1] = a[i + 1];
		subSum[i + 1] += subSum[i];
	}

	ll ans = 0;

	for (int z = 0; z < m; z++)
	{
		int curLength = 0;
		ll curSum = 0;
		for (int i = 1 + z; i <= n; i++)
		{
			curSum += a[i], curLength++;

			ll tmp = subSum[i] - subSum[i - curLength];
			ll minus = k * ceil(((double)curLength / m));

			tmp -= minus;

			if (tmp == 6)
			{
				int stop_here = 0;
			}
			ans = max(ans, tmp);

			if (curLength % m == 0)
			{
				if (tmp <= 0)
				{
					curSum = 0;
					curLength = 0;
				}
			}
		}
	}

	cout << ans;
}