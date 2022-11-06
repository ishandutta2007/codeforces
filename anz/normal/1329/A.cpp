#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, m;
ll l[100001];
ll last[100001];
int ans[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	ll sum = 0;
	for (int i = 0; i < m; i++)
		cin >> l[i], sum += l[i];

	if (sum < n)
	{
		cout << -1;
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		last[i] = i + l[i];
		if (i) last[i] = max(last[i - 1], last[i]);

		if (last[i] > n)
		{
			cout << -1;
			return 0;
		}
	}

	ll colored = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		if (last[i] + colored < n) ans[i] = n - colored - (l[i] - 1);
		else ans[i] = i + 1;
		colored += l[i];
	}

	for (int i = 0; i < m; i++) cout << ans[i] << ' ';
}