#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, m;
int ans[100001];
int cur[100001];
int nxt[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(ans, -1, sizeof ans);

	cin >> n >> m;
	cur[0] = 1;

	for (int k = 1; k <= n; k++)
	{
		ll t, x, y; cin >> t >> x >> y;

		memset(nxt, 0, sizeof nxt);
		for (int i = m; i >= 0; i--)
		{
			if (!cur[i]) continue;

			if (t == 1)
			{
				ll c = i;
				for (int j = 0; j <= y && c <= m && !nxt[c]; j++)
				{
					nxt[c] = 1;
					c = (c * 100000 + x - 1 + 100000) / 100000;
				}
			}
			else
			{
				ll c = i;
				for (int j = 0; j <= y && c <= m && !nxt[c]; j++)
				{
					nxt[c] = 1;
					c = (c * x - 1 + 100000) / 100000;
				}
			}
		}

		memcpy(cur, nxt, sizeof cur);
		for (int i = 1; i <= m; i++)
		{
			if (!cur[i] || ans[i] != -1) continue;
			ans[i] = k;
		}
	}

	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
}