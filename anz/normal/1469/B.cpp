#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int r[101], b[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> r[i], r[i] += r[i - 1];
		cin >> m;
		for (int i = 1; i <= m; i++) cin >> b[i], b[i] += b[i - 1];

		int ans = *max_element(r, r + n + 1) + *max_element(b, b + m + 1);

		cout << ans << '\n';
	}
}