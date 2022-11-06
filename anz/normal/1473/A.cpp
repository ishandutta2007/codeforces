#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, d;
int a[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 0; i < n; i++) cin >> a[i];

		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > d) flag = false;
		}

		sort(a, a + n);
		if (flag || a[0] + a[1] <= d) cout << "YES\n";
		else cout << "NO\n";
	}
}