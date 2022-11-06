#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, m;
ll a[200001];
ll b[200001];
vector <ll> a1, a2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		a1.clear();
		a2.clear();

		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			if (b[i] == 1) a1.push_back(a[i]);
			else a2.push_back(a[i]);
		}

		sort(a1.rbegin(), a1.rend());
		sort(a2.rbegin(), a2.rend());

		ll cm = 0, ci = 0;
		int ptr1 = 0, ptr2 = 0;

		while (ptr1 < a1.size() && cm < m)
		{
			cm += a1[ptr1++];
			ci += 1;
		}

		while (ptr2 < a2.size() && cm < m)
		{
			cm += a2[ptr2++];
			ci += 2;
		}

		if (cm < m)
		{
			cout << "-1\n";
			continue;
		}

		ll ans = ci;

		while (--ptr1 >= 0)
		{
			cm -= a1[ptr1];
			ci -= 1;

			while (ptr2 < a2.size() && cm < m)
			{
				cm += a2[ptr2++];
				ci += 2;
			}

			if (cm >= m) ans = min(ans, ci);
		}

		cout << ans << '\n';
	}
}