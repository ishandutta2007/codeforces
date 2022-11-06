#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string board[2001];

int exl[10][2001];
int exr[10][2001];
int exu[10][2001];
int exd[10][2001];

int ml[10], mr[10], mu[10], md[10];

int ans[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				exl[j][i] = -1;
				exr[j][i] = -1;
				exu[j][i] = -1;
				exd[j][i] = -1;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			ans[i] = 0;
			ml[i] = mr[i] = mu[i] = md[i] = -1;
		}

		for (int i = 0; i < n; i++) cin >> board[i];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int num = board[i][j] - '0';
				if (exl[num][i] == -1) exl[num][i] = j;
				exr[num][i] = j;

				if (exu[num][j] == -1) exu[num][j] = i;
				exd[num][j] = i;

				if (ml[num] == -1) ml[num] = j;
				else ml[num] = min(ml[num], j);

				if (mr[num] == -1) mr[num] = j;
				else mr[num] = max(mr[num], j);

				if (mu[num] == -1) mu[num] = i;
				else mu[num] = min(mu[num], i);

				if (md[num] == -1) md[num] = i;
				else md[num] = max(md[num], i);
			}
		}

		for (int k = 0; k < 10; k++)
		{
			for (int i = 0; i < n; i++)
			{
				if (exl[k][i] == -1) continue;

				int cl = exl[k][i], cr = exr[k][i];
				int cu = mu[k], cd = md[k];

				int ma = max(n - 1 - cl, cr);
				ans[k] = max(ans[k], ma * max(cd - i, i - cu));
				ans[k] = max(ans[k], (cr - cl) * max(n - 1 - i, i));
			}

			for (int i = 0; i < n; i++)
			{
				if (exu[k][i] == -1) continue;

				int cu = exu[k][i], cd = exd[k][i];
				int cl = ml[k], cr = mr[k];

				int ma = max(n - 1 - cu, cd);
				ans[k] = max(ans[k], ma * max(cr - i, i - cl));
				ans[k] = max(ans[k], (cd - cu) * max(n - 1 - i, i));
			}
		}

		for (int k = 0; k < 10; k++) cout << ans[k] << ' ';
		cout << '\n';
	}
}