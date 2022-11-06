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

ll n, k;
ll a[300001];
pll d[300001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll ans = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i)
		{
			d[i] = { a[i] - a[i - 1],i };
			ans += a[i] - a[i - 1];
		}
	}

	sort(d + 1, d + n);
	for (int i = 1; i < k; i++)
	{
		ans -= d[n - i].first;
	}

	cout << ans;
}