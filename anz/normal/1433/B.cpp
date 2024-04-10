#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;

		int l = -1, r = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == 1)
			{
				if (l == -1) l = i;
				r = i;
			}
		}

		while (l + 1 < n && a[l + 1] == 1) l++;
		while (r - 1 >= 0 && a[r - 1] == 1) r--;

		int ans = 0;
		for (int i = l + 1; i < r; i++) if (a[i] == 0) ans++;

		cout << ans << '\n';
	}
}