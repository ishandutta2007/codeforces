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

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);

		bool ans = true;
		for (int i = 1; i < n; i++) if (a[i - 1] + 1 < a[i]) ans = false;

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}