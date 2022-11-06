#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int a[1001], b[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		int ans = -1;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j]) ans = a[i];
		}

		if (ans != -1) cout << "YES\n1 " << ans << '\n';
		else cout << "NO\n";
	}
}