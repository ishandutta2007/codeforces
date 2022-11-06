#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cpdb;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
ll tag[5001];
ll s[5001];
ll dp[5001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> tag[i];
		for (int i = 0; i < n; i++) cin >> s[i];
		
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (tag[i] == tag[j]) continue;
				ll sj = dp[j], si = dp[i];
				ll point = llabs(s[i] - s[j]);
				dp[j] = max(dp[j], si + point);
				dp[i] = max(dp[i], sj + point);
			}
		}

		cout << *max_element(dp, dp + n) << '\n';
	}
}