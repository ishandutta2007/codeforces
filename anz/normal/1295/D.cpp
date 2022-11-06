#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll coprime(ll n, vector <ll>& div)
{
	if (n < 1) return 0;

	ll ans = n;
	for (int i = 1; i < (1 << div.size()); i++)
	{
		ll cd = 1;
		int cnt = 0;

		for (int j = 0; j < div.size(); j++)
		{
			if(i & (1 << j))
			{
				cnt++;
				cd *= div[j];
			}
		}

		if (cnt % 2)
			ans -= n / cd;
		else
			ans += n / cd;
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll a, m; cin >> a >> m;
		ll g = gcd(a, m);

		a /= g, m /= g;

		vector <ll> div;
		ll t = m;
		for (ll i = 2; i * i <= m; i++)
		{
			if (t % i == 0)
			{
				div.push_back(i);
				while (t % i == 0) { t /= i; }
			}
		}
		if (t > 1) div.push_back(t);

		ll res = coprime(m + a - 1, div);
		res -= coprime(a - 1, div);

		cout << res << '\n';
	}
}