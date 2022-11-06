#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector <ll> dv;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll tmp = 4;
	while (tmp < 1e9)
	{
		dv.push_back(tmp - 1);
		tmp *= 2;
	}

	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		for (auto it : dv)
		{
			if (n % it == 0)
			{
				cout << n / it << '\n';
				break;
			}
		}
	}
}