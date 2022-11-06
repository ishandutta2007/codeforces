#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		vector <int> b[2];
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			b[x % 2].push_back(x);
		}

		int p = 0;
		for (int x : b[0]) a[p++] = x;
		for (int x : b[1]) a[p++] = x;

		int ans = 0;
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
		{
			if (gcd(a[i], 2 * a[j]) > 1) ans++;
		}

		cout << ans << '\n';
	}
}