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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll n, k;
ll a[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);

	ll ans = -1;

	ll c = 1;
	for (int i = n / 2; i < n - 1; i++)
	{
		ll d = a[i + 1] - a[i];
		if (c*d <= k)
		{
			k -= c * d;
			c++;
			a[i] = a[i + 1];
		}
		else
		{
			ll tmp = k / c;

			ans = a[i] + tmp;
			break;
		}
	}

	if (ans != -1)
	{
		cout << ans;
		return 0;
	}

	ans = a[n - 1] + k / c;
	cout << ans;
}