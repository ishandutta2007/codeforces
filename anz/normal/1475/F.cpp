#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string a[1001];
string b[1001];

int board[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			board[i][j] = (a[i][j] - '0') ^ (b[i][j] - '0');

		bool ans = true;
		for (int i = 1; i < n; i++)
		{
			bool b1 = true, b2 = true;
			for (int j = 0; j < n; j++)
			{
				if (board[i - 1][j] != board[i][j]) b1 = false;
				if (board[i - 1][j] == board[i][j]) b2 = false;
			}

			if (!b1 && !b2) ans = false;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}