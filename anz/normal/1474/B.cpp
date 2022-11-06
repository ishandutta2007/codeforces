#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector <ll> p;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	p.push_back(2);
	for (ll i = 3; i <= 100000; i++)
	{
		bool flag = true;
		for (int j = 0; j < p.size() && p[j] * p[j] <= i; j++)
		{
			if (i % p[j] == 0)
			{
				flag = false;
				break;
			}
		}

		if (flag) p.push_back(i);
	}

	int t; cin >> t;
	while (t--)
	{
		ll d; cin >> d;

		ll a = *lower_bound(p.begin(), p.end(), 1 + d);
		ll b = *lower_bound(p.begin(), p.end(), a + d);

		cout << a * b << '\n';
	}
}