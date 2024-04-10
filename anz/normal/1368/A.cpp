#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		ll a, b, n; cin >> a >> b >> n;
		
		int ans = 0;
		while (a <= n && b <= n)
		{
			if (a > b) swap(a, b);
			a += b;
			ans++;
		}

		cout << ans << '\n';
	}
}