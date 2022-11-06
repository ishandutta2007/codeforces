#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cpdb;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int cnt[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof cnt);
		
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			cnt[a % m]++;
		}

		int ans = 0;
		if (cnt[0]) ans++;
		for (int i = 1; i < (m + 1) / 2; i++)
		{
			int lc = cnt[i], rc = cnt[m - i];
			if (lc == 0 && rc == 0) continue;
			if (lc > rc) swap(lc, rc);
			if (lc == 0)
			{
				ans += rc;
				continue;
			}

			ans += 1 + max(0, rc - (lc + 1));
		}

		if (m % 2 == 0 && cnt[m / 2]) ans++;

		cout << ans << '\n';
	}
}