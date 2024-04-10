#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n[3];
vector <ll> st[3];
ll sum[3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 3; i++) cin >> n[i];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n[i]; j++)
		{
			ll x; cin >> x;
			sum[i] += x;
			st[i].push_back(x);
		}
	}

	for (int i = 0; i < 3; i++)
		sort(st[i].begin(), st[i].end());

	ll ans = numeric_limits<ll>::min();
	for (int k = 0; k < 3; k++)
	{
		vector <ll>& v1 = st[k];
		vector <ll>& v2 = st[(k + 1) % 3];
		vector <ll>& v3 = st[(k + 2) % 3];

		ll res = sum[(k + 2) % 3];

		ll r1 = sum[k] + sum[(k + 1) % 3] - 2 * (v1[0] + v2[0]);
		ll r2 = sum[k] - sum[(k + 1) % 3];
		ll r3 = sum[(k + 1) % 3] - sum[k];

		res += max(r1, max(r2, r3));

		ans = max(ans, res);
	}

	cout << ans;
}