#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, k;
pii s[201];
pii f[201];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) cin >> s[i].first >> s[i].second;
	for (int i = 0; i < k; i++) cin >> f[i].first >> f[i].second;

	int ans = (n - 1) + (m - 1) + n * m - 1;
	cout << ans << '\n';
	for (int i = 0; i < n - 1; i++) cout << "U";
	for (int i = 0; i < m - 1; i++) cout << "L";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (i % 2 == 0) cout << "R";
			else cout << "L";
		}
		if (i != n - 1) cout << "D";
	}
}