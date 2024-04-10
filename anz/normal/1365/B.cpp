#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[501];
int b[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		bool isExist[2] = { 0,0 };
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i], isExist[b[i]] = 1;

		if (isExist[0] && isExist[1]) cout << "Yes\n";
		else
		{
			bool ans = true;
			for (int i = 1; i < n; i++)
			{
				if (a[i - 1] > a[i]) ans = false;
			}

			if (ans) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}