#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int a[2], b[2];
		cin >> a[0] >> a[1] >> b[0] >> b[1];
		
		bool ans = false;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
		{
			if (a[i] == b[j] && a[1 - i] + b[1 - j] == a[i]) ans = true;
		}

		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
}