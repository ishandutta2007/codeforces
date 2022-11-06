#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int cnt[1024];

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
			int s; cin >> s;
			cnt[s]++;
		}

		bool hasAns = false;
		for (int i = 1; i < 1024; i++)
		{
			bool flag = true;
			int ccnt[1024];
			memcpy(ccnt, cnt, sizeof cnt);

			for (int j = 0; j < 1024; j++)
			{
				if (ccnt[i ^ j] != ccnt[j])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				hasAns = true;
				cout << i << '\n';
				break;
			}
		}

		if (!hasAns) cout << "-1\n";
	}
}