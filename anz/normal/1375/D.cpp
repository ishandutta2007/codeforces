#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[1001];

int cnt[1001];

int MEX()
{
	for (int i = 0; i <= n; i++)
	{
		if (cnt[i]==0) return i;
	}
}

vector <int> ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		ans.clear();
		for (int i = 0; i <= n; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			cnt[a[i]]++;
		}

		for (int i = 0; i < n * 2; i++)
		{
			int x = MEX();

			if (x == 0)
			{
				int res = -1;
				for (int j = 1; j <= n; j++)
				{
					if (a[j] != j)
					{
						res = j;
						break;
					}
				}

				if (res == -1) break;

				int tmp = a[res];
				a[res] = 0;
				ans.push_back(res);

				cnt[tmp]--;
				cnt[0]++;

				continue;
			}

			int tmp = a[x];
			a[x] = x;
			ans.push_back(x);

			cnt[tmp]--;
			cnt[x]++;
		}


		cout << ans.size() << '\n';
		for (int i : ans) cout << i << ' ';
		cout << '\n';
	}
}