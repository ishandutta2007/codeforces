#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
string s;

int psum[3][3][200001];

int v[6][3] =
{
	{0,1,2},
	{0,2,1},
	{1,0,2},
	{1,2,0},
	{2,0,1},
	{2,1,0}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	cin >> s;

	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			psum[i % 3][k][i] = (s[i - 1] - 'a' == k ? 0 : 1);
		}

		for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++)
			psum[j][k][i] += psum[j][k][i - 1];
	}

	while (m--)
	{
		int l, r; cin >> l >> r;

		int ans = 1e9;
		for (int x = 0; x < 6; x++)
		{
			int res = 0;
			for (int i = 0; i < 3; i++)
			{
				res += psum[i][v[x][i]][r] - psum[i][v[x][i]][l - 1];
			}

			ans = min(ans, res);
		}

		cout << ans << '\n';
	}
}