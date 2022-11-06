#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <ll> a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		a.clear(), b.clear();

		for (int i = 0; i < n; i++)
		{
			ll x; cin >> x;
			if (x % 2 == 0) a.push_back(x);
			else b.push_back(x);
		}

		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());

		int aptr = 0, bptr = 0;

		ll asum = 0, bsum = 0;

		int turn = 0;
		while (aptr < a.size() || bptr < b.size())
		{
			ll ca = aptr < a.size() ? a[aptr] : 0;
			ll cb = bptr < b.size() ? b[bptr] : 0;

			if (turn == 0)
			{
				if (aptr < a.size())
				{
					if (ca >= cb)
					{
						asum += a[aptr];
						aptr++;
					}
					else bptr++;
				}
				else bptr++;
			}
			else
			{
				if (bptr < b.size())
				{
					if (cb >= ca)
					{
						bsum += b[bptr];
						bptr++;
					}
					else aptr++;
				}
				else aptr++;
			}

			turn = 1 - turn;
		}

		if (asum > bsum) cout << "Alice\n";
		else if (asum < bsum) cout << "Bob\n";
		else cout << "Tie\n";
	}
}