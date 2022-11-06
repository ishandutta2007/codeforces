#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int a[31][31];

vector <pii> idx[100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		for (int i = 0; i < 100; i++) idx[i].clear();

		cin >> n >> m;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			idx[i + j].push_back({ i,j });
		}

		int ans = 0;
		for (int k = 0; k < (n + m - 1) / 2; k++)
		{
			int cnt[2] = { 0,0 };
			for (pii it : idx[k]) cnt[a[it.first][it.second]]++;
			for (pii it : idx[n + m - 2 - k]) cnt[a[it.first][it.second]]++;

			ans += min(cnt[0], cnt[1]);
		}

		cout << ans << '\n';
	}
}