#include <bits/stdc++.h>
#include <random>
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
		int n; cin >> n;
		int a[101];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			int b; cin >> b;
			string s; cin >> s;
			for (char c : s)
			{
				if (c == 'D') ++a[i];
				else --a[i];
			}

			a[i] = ((a[i] % 10) + 10) % 10;
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
}