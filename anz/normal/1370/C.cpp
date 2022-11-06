#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const string WIN = "Ashishgup";
const string LOSE = "FastestFinger";

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		if (n == 1) cout << LOSE << '\n';
		else if (n == 2) cout << WIN << '\n';
		else if (n % 2 == 1) cout << WIN << '\n';
		else
		{
			n /= 2;
			if (n % 2 == 1)
			{
				bool flag = true;
				for (ll i = 2; i*i <= n; i++)
				{
					if (n % i == 0) flag = false;
				}

				if (flag) cout << LOSE << '\n';
				else cout << WIN << '\n';
			}
			else
			{
				while (n % 2 == 0) n /= 2;
				if (n == 1) cout << LOSE << '\n';
				else cout << WIN << '\n';
			}
		}
	}
}