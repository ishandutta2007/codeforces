#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> b;

		int last = -1;
		for (int i = 0; i < n; i++)
		{
			if (b[i] == '0')
			{
				if (last == 1) cout << 0, last = 0;
				else cout << 1, last = 1;
			}
			else
			{
				if (last == 2) cout << 0, last = 1;
				else cout << 1, last = 2;
			}
		}

		cout << '\n';
	}
}