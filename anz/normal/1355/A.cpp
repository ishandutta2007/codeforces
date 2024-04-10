#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

pii calc(ll x)
{
	vector <int> v;
	while (x)
	{
		v.push_back(x % 10);
		x /= 10;
	}

	int mn = *min_element(v.begin(), v.end());
	int mx = *max_element(v.begin(), v.end());

	return { mn,mx };
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll a, k; cin >> a >> k;

		k--;
		while (k--)
		{
			pii res = calc(a);
			if (res.first == 0) break;

			a += res.first * res.second;
		}

		cout << a << '\n';
	}
}