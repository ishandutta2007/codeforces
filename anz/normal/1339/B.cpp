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
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);

		cout << a[n / 2];
		for (int i = 1; i <= (n - 1) / 2; i++)
		{
			cout << ' ' << a[n / 2 - i] << ' ' << a[n / 2 + i];
		}
		if (n % 2 == 0) cout << ' ' << a[0];
		cout << "\n";
	}
}