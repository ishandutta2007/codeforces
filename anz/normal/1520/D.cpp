#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];
map <int, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		mp.clear();

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			mp[a[i] - i]++;
		}

		ll ans = 0;
		for (auto it : mp)
		{
			ll x = it.second;
			ans += x * (x - 1) / 2;
		}

		cout << ans << '\n';
	}
}