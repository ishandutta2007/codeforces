#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = numeric_limits<ll>::max();

ll n, r1, r2, r3, d;
ll a[1000001];
ll dp[2][1000001];

ll solve(int t, int idx)
{
	ll& ret = dp[t][idx];

	if (idx == n)
	{
		if (t == 0) return ret = 0;
		return ret = d + d + min(r1, min(r2, r3));
	}

	if (ret != -1) return ret;

	ll t1 = min(r1, r3) * a[idx] + r3;
	if (t)
	{
		t1 += d + min(r1, min(r2, r3));
		if (idx != n - 1) t1 += d;
	}

	t1 += solve(0, idx + 1);

	ll t2 = min(r1, r3) * a[idx] + min(r1, r2);
	if (t)
	{
		t2 += d + min(r1, min(r2, r3));
		t2 += d + min(r1, min(r2, r3));
		t2 += solve(0, idx + 1);
	}
	else
	{
		t2 += solve(1, idx + 1);
	}

	ll t3 = r2;
	if (t)
	{
		t3 += d + min(r1, min(r2, r3));
		t3 += d + min(r1, min(r2, r3));
		t3 += solve(0, idx + 1);
	}
	else
	{
		t3 += solve(1, idx + 1);
	}

	return ret = min(t1, min(t2, t3));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> r1 >> r2 >> r3 >> d;
	for (int i = 0; i < n; i++) cin >> a[i];

	memset(dp, -1, sizeof dp);

	ll ans = solve(0, 0) + d * (n - 1);
	cout << ans;
}