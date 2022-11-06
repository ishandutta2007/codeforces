#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int R, G, B;
ll r[201], g[201], b[201];

ll dp[201][201][201];
ll solve(int ri, int gi, int bi)
{
	ll& ret = dp[ri][gi][bi];
	if (ret != -1) return ret;

	ret = 0;

	if (ri < R && gi < G)
	{
		ll res = solve(ri + 1, gi + 1, bi) + r[ri] * g[gi];
		ret = max(ret, res);
	}

	if (gi < G && bi < B)
	{
		ll res = solve(ri, gi + 1, bi + 1) + g[gi] * b[bi];
		ret = max(ret, res);
	}

	if (bi < B && ri < R)
	{
		ll res = solve(ri + 1, gi, bi + 1) + b[bi] * r[ri];
		ret = max(ret, res);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> R >> G >> B;
	for (int i = 0; i < R; i++) cin >> r[i];
	for (int i = 0; i < G; i++) cin >> g[i];
	for (int i = 0; i < B; i++) cin >> b[i];

	sort(r, r + R); reverse(r, r + R);
	sort(g, g + G); reverse(g, g + G);
	sort(b, b + B); reverse(b, b + B);

	memset(dp, -1, sizeof dp);

	cout << solve(0, 0, 0);
}