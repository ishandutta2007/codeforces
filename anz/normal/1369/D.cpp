#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;
ll ans[2000001];
int tmp[2000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ans[3] = 1, ans[4] = 1;
	tmp[3] = 1;

	for (int i = 5; i <= 2000000; i++)
	{
		ans[i] = (ans[i - 1] + ans[i - 2] * 2) % MOD;
		if (tmp[i - 2] == 0 && tmp[i - 1] == 0)
		{
			tmp[i] = 1;
			ans[i] = (ans[i] + 1) % MOD;
		}
	}

	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		cout << ans[n] * 4 % MOD << '\n';
	}
}