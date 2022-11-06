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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll n, p; cin >> n >> p;

	n -= p;
	for (int k = 1; n >= 1; k++)
	{
		int cnt = 0;
		for (int i = 0; i <= 35; i++)
		{
			if (n & (1ll << i))
			{
				cnt++;
				if (cnt > k) break;
			}
		}

		if (cnt <= k && k <= n)
		{
			cout << k;
			return 0;
		}

		n -= p;
	}

	cout << -1;
}