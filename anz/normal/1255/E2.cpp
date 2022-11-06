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

int n;
int a[1000001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	if (sum <= 1)
	{
		cout << "-1";
		return 0;
	}

	vector <ll> div;

	ll t = sum;
	for (ll i = 2; i*i <= t; i++)
	{
		if (t % i == 0)
		{
			div.push_back(i);
			while (t % i == 0)
				t /= i;
		}
	}
	if (t != 1) div.push_back(t);

	ll ans = numeric_limits<ll>::max();

	for (ll md : div)
	{
		ll remain = 0;
		ll res = 0;
		for (int i = 0; i < n; i++)
		{
			remain = (remain + a[i]) % md;
			res += min(remain, md - remain);
		}
		ans = min(ans, res);
	}


	cout << ans;
}