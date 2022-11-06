#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, p;
ll a[100001];
vector <int> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> p;
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);
	ll st = 0;
	ll ed = a[n - 1];
	for (int i = 0; i < n; i++)
	{
		ll res = a[i] - i;
		st = max(st, res);
	}

	for (int t = st; t <= ed; t++)
	{
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			int res = (a + n) - upper_bound(a, a + n, t + i);
			if ((n - i - res) % p == 0) flag = false;
		}

		if (flag) ans.push_back(t);
	}

	cout << ans.size() << '\n';
	for (int it : ans) cout << it << ' ';
}