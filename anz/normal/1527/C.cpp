#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[100001];
map <int, ll> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		mp.clear();

		ll ans = 0;
		ll last = 0;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			last += mp[a[i]];
			mp[a[i]] += i + 1;
			ans += last;
		}

		cout << ans << '\n';
	}
}