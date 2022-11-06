#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;

string x = "2020";

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> s;

		bool ans = false;
		for (int i = 0; i < 5; i++)
		{
			bool flag = true;
			for (int j = 0; j < 4 - i; j++)
			{
				if (s[j] != x[j]) flag = false;
			}

			for (int j = 0; j < i; j++)
			{
				if (s[n - 1 - j] != x[3 - j]) flag = false;
			}

			if (flag) ans = true;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}