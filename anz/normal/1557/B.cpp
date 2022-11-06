#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
pll a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			ll x; cin >> x;
			a[i] = { x, i };
		}

		sort(a, a + n);

		int ck = 1;
		for (int i = 1; i < n; i++) if (a[i - 1].second + 1 != a[i].second) ck++;

		if (ck <= k) cout << "YES\n";
		else cout << "NO\n";
	}
}