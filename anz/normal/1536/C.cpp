#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;

map <pii, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		mp.clear();

		cin >> n >> s;

		int a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'D') a++;
			else b++;

			int g = gcd(a, b);
			cout << ++mp[{a / g, b / g}] << ' ';
		}

		cout << '\n';
	}
}