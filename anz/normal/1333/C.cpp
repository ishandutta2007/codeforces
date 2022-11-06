#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[200001];
ll psum[200001];

map<ll, ll> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		psum[i] = a[i] + psum[i - 1];
	}

	ll ans = 0;
	ll left = -1;
	mp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (mp.count(psum[i]))
		{
			left = max(left, mp[psum[i]]);
		}
		mp[psum[i]] = i;
		ans += i - (left + 1);
	}

	cout << ans;
}