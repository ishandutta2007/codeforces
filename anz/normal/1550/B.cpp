#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, a, b;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> a >> b;
		cin >> s;
		int res = 1;
		int last = s[0];
		for (int i = 1; i < n; i++)
		{
			if (s[i] != last)
			{
				res++;
				last = s[i];
			}
		}

		if (b >= 0) cout << (a + b) * n << '\n';
		else cout << a * n + b * (res / 2 + 1) << '\n';
	}
}