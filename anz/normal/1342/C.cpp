#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll _LCM;
ll psum[40001];

ll solve(ll x)
{
	ll res = x / _LCM * psum[_LCM];
	res += psum[x % _LCM];
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll a, b, q; cin >> a >> b >> q;
		if (a > b) swap(a, b);

		ll g = gcd(a, b);
		_LCM = a * b / g;
		
		memset(psum, 0, sizeof psum);
		for (ll i = 1; i <= _LCM; i++)
		{
			if (i % a % b != i % b % a) psum[i] = 1;
			psum[i] += psum[i - 1];
		}

		vector <ll> ans;
		while (q--)
		{
			ll l, r; cin >> l >> r;
			ans.push_back(solve(r) - solve(l - 1));
		}

		for (auto it : ans) cout << it << ' ';
		cout << '\n';
	}
}