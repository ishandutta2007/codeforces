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

	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			sum += a;
		}

		if (sum == m) cout << "YES\n";
		else cout << "NO\n";
	}
}