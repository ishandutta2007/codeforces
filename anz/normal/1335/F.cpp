#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <string> color;
vector <string> dir;

int par[1000001][21];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		color.resize(n);
		dir.resize(n);

		for (int i = 0; i < n; i++)
			cin >> color[i];
		for (int i = 0; i < n; i++)
			cin >> dir[i];

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			int num = i * m + j;
			if (dir[i][j] == 'U')
				par[num][0] = num - m;
			else if (dir[i][j] == 'D')
				par[num][0] = num + m;
			else if (dir[i][j] == 'L')
				par[num][0] = num - 1;
			else if (dir[i][j] == 'R')
				par[num][0] = num + 1;
		}

		for (int j = 1; j <= 20; j++)
		{
			for (int i = 0; i < n * m; i++)
				par[i][j] = par[par[i][j - 1]][j - 1];
		}

		set <int> all, black;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			int num = i * m + j;
			int p = par[num][20];
			all.insert(p);
			if (color[i][j] == '0') black.insert(p);
		}

		cout << all.size() << ' ' << black.size() << '\n';
	}
}