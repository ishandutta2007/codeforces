#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ans[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int c = n;
		for (int i = 1; i <= n; i += 2) ans[i] = c--;
		for (int i = n % 2 == 0 ? n : n - 1; i >= 1; i -= 2) ans[i] = c--;

		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}