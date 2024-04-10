#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector <ll> card;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll d = 2;
	ll sum = 0;

	while (sum <= 1e9)
	{
		sum += d;
		card.push_back(sum);
		d += 3;
	}

	reverse(card.begin(), card.end());

	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;

		int ans = 0;
		for (ll tmp : card)
		{
			while (n >= tmp)
			{
				n -= tmp;
				ans++;
			}
		}

		cout << ans << '\n';
	}
}