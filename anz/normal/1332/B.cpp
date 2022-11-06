#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[1001];
bool cache[1001];
int ans[1001];
int p[11] = { 2,3,5,7,11,13,17,19,23,29,31 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i], cache[i] = 0;

		vector <int> res[11];
		for (int k = 0; k < 11; k++)
		{
			for (int i = 0; i < n; i++)
			{
				if (cache[i]) continue;
				if (a[i] % p[k] == 0)
				{
					cache[i] = 1;
					res[k].push_back(i);
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < 11; i++) if (!res[i].empty()) cnt++;
		cout << cnt << '\n';

		cnt = 0;
		for (int i = 0; i < 11; i++)
		{
			if (res[i].empty()) continue;
			for (auto it : res[i]) ans[it] = cnt + 1;
			cnt++;
		}

		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}