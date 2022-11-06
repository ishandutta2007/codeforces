#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		int ans1 = 0, ans2 = 0;
		int lptr = 0, rptr = n - 1;
		int last = 0;

		int cnt = 0;
		while (lptr <= rptr)
		{
			int cur = 0;
			while (lptr <= rptr)
			{
				cur += a[lptr++];
				if (cur > last) break;
			}
			ans1 += cur;
			last = cur;
			cnt++;

			if (lptr > rptr) break;

			cur = 0;
			while (lptr <= rptr)
			{
				cur += a[rptr--];
				if (cur > last) break;
			}
			ans2 += cur;
			last = cur;
			cnt++;
		}

		cout << cnt << ' ' << ans1 << ' ' << ans2 << '\n';
	}
}