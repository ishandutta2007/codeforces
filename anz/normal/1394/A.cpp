#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, d, m;
vector <ll> m1, m2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> d >> m;
	m1.push_back(0);
	for (int i = 0; i < n; i++)
	{
		ll a; cin >> a;
		if (a > m) m1.push_back(a);
		else m2.push_back(a);
	}

	sort(m1.begin() + 1, m1.end());
	reverse(m1.begin() + 1, m1.end());
	for (int i = 1; i < m1.size(); i++) m1[i] += m1[i - 1];
	sort(m2.begin(), m2.end());
	reverse(m2.begin(), m2.end());

	ll ans = 0;

	ll cm2 = 0;
	for (ll i = 0; i <= m2.size(); i++)
	{
		ll res = cm2;
		ll rm = max(n - i, 0ll);
		rm = (rm - 1) / (d + 1) + 1;
		rm = min(rm, (ll)m1.size() - 1);
		res += m1[rm];

		ans = max(ans, res);

		if (i < m2.size()) cm2 += m2[i];
	}

	cout << ans;
}