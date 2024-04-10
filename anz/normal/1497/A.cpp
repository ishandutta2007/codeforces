#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cpdb;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int cnt[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof cnt);

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			cnt[a]++;
		}

		for (int i = 0; i <= 100; i++)
		{
			if (cnt[i])
			{
				cout << i << ' ';
				cnt[i]--;
			}
			else break;
		}

		for (int i = 0; i <= 100; i++)
		{
			for (int j = 0; j < cnt[i]; j++) cout << i << ' ';
		}
		cout << '\n';
	}
}