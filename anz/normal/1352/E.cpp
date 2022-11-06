#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[8001];
int cnt[8001];
bool isUsed[8001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof cnt);
		memset(isUsed, 0, sizeof isUsed);

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			cnt[a[i]]++;
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int sum = a[i];
			for (int j = i + 1; j < n; j++)
			{				
				sum += a[j];
				if (sum > n) break;
				if (cnt[sum] && !isUsed[sum])
				{
					ans += cnt[sum];
					isUsed[sum] = 1;
				}
			}
		}

		cout << ans << '\n';
	}
}