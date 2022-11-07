#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, q;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> q;
		cin >> s;

		while (q--)
		{
			bool ans = false;
			int l, r; cin >> l >> r; l--, r--;
			for (int i = 0; i < l; i++) if (s[i] == s[l]) ans = true;
			for (int i = r + 1; i < n; i++) if (s[i] == s[r]) ans = true;

			if (ans) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}