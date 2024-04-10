#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int a[51][51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			cin >> a[i][j];

		int row = 0, col = 0;
		for (int i = 0; i < n; i++)
		{
			bool flag = true;
			for (int j = 0; j < m; j++) if (a[i][j]) flag = false;
			if (flag) row++;
		}
		for (int i = 0; i < m; i++)
		{
			bool flag = true;
			for (int j = 0; j < n; j++) if (a[j][i]) flag = false;
			if (flag) col++;
		}

		int res = min(row, col);
		if (res % 2) cout << "Ashish\n";
		else cout << "Vivek\n";
	}
}