#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll u[200001];
ll s[200001];
vector <ll> a[200001];
ll ans[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			ans[i] = 0;
		}

		for (int i = 0; i < n; i++) cin >> u[i];
		for (int i = 0; i < n; i++) cin >> s[i];
		for (int i = 0; i < n; i++)
			a[u[i]].push_back(s[i]);

		for (int i = 1; i <= n; i++)
		{
			sort(a[i].rbegin(), a[i].rend());
			for (int j = 1; j < a[i].size(); j++)
				a[i][j] += a[i][j - 1];

			for (int j = 1; j <= a[i].size(); j++)
			{
				int sz = a[i].size() / j * j;
				ans[j] += a[i][sz - 1];
			}
		}

		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}