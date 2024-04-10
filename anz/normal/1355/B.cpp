#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int e[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> e[i];
		sort(e, e + n);

		int ans = 0;

		int curCnt = 0;
		int curMax = 0;
		for (int i = 0; i < n; i++)
		{
			curMax = max(curMax, e[i]);
			curCnt++;

			if (curCnt >= curMax)
			{
				ans++;
				curCnt = 0;
				curMax = 0;
			}
		}

		cout << ans << '\n';
	}
}