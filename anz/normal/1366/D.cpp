#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int ans[2][500001];

vector <int> p;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(ans, -1, sizeof ans);

	p.push_back(2);
	for (int i = 3; i * i <= 10000000; i++)
	{
		bool flag = true;
		for (int j = 0; j < p.size() && p[j] * p[j] <= i; j++)
		{
			if (i % p[j] == 0)
			{
				flag = false;
				break;
			}
		}

		if (flag) p.push_back(i);
	}

	cin >> n;
	for (int t = 0; t < n; t++)
	{
		int a; cin >> a;

		for (int i = 0; i < p.size() && p[i] * p[i] < a; i++)
		{
			if (a % p[i] == 0)
			{
				int ta = a;
				while (ta % p[i] == 0) ta /= p[i];

				if (ta > 1)
				{
					ans[0][t] = p[i];
					ans[1][t] = ta;
					break;
				}

			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++) cout << ans[i][j] << ' ';
		cout << '\n';
	}
}