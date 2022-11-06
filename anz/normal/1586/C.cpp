#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
string board[1000001];
int psum[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];

	for (int j = 1; j < m; j++)
	{
		bool flag = false;
		for (int i = 0; i + 1 < n; i++)
		{
			if (board[i][j] == 'X' && board[i + 1][j - 1] == 'X')
				flag = true;
		}

		if (flag) psum[j + 1] = 1;
		psum[j + 1] += psum[j];
	}

	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;
		if (psum[r] - psum[l] == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}