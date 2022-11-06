#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;
int n, k, m;
struct query
{
	int l, r, x;
} ql[500010], qr[500010];

bool c1(query q1, query q2) { return q1.l < q2.l; }
bool c2(query q1, query q2) { return q1.r < q2.r; }

ll dp[500010];
ll psum[500010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> ql[i].l >> ql[i].r >> ql[i].x;
		qr[i] = ql[i];
	}
		
	sort(ql, ql + m, c1);
	sort(qr, qr + m, c2);

	ll ans = 1;
	for (int x = 0; x < k; x++)
	{
		memset(dp, 0, sizeof dp);
		memset(psum, 0, sizeof psum);

		int ql_ptr = 0;
		int qr_ptr = 0;
		int last0 = 0;
		int last1 = 0;
		
		for (int i = 1; i <= n + 1; i++)
		{
			while (ql_ptr < m && ql[ql_ptr].l == i)
			{
				if (ql[ql_ptr].x & (1 << x))
					last1 = max(last1, ql[ql_ptr].r);
				ql_ptr++;
			}

			if (last1 == 0)
			{
				if (last0 == 0) dp[i] = (psum[i - 1] + 1) % MOD;
				else dp[i] = (psum[i - 1] - psum[last0 - 1] + MOD) % MOD;
			}

			psum[i] = (psum[i - 1] + dp[i]) % MOD;

			while (qr_ptr < m && qr[qr_ptr].r == i)
			{
				if (!(qr[qr_ptr].x & (1 << x)))
					last0 = max(last0, qr[qr_ptr].l);
				qr_ptr++;
			}

			while (last1 == i) last1 = 0;;
		}

		ans *= dp[n + 1];
		ans %= MOD;
	}

	cout << ans;
}