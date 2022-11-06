#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[300001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		int mx = *max_element(a, a + n);
		int ans = -1;

		for (int i = 0; i < n; i++)
		{
			if (a[i] != mx) continue;
			if (i - 1 >= 0 && a[i] > a[i - 1]) ans = i + 1;
			if (i + 1 < n && a[i] > a[i + 1]) ans = i + 1;
		}

		cout << ans << '\n';
	}
}