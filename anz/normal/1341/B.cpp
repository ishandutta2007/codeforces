#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
int a[200001];
int peak[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			peak[i] = 0;
		}
		for (int i = 1; i < n - 1; i++)
		{
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) peak[i] = 1;
		}
		for (int i = 1; i < n; i++) peak[i] += peak[i - 1];
		
		int ans = 0;
		int l = 0;
		for (int i = 0; i <= n - k; i++)
		{
			int res = peak[k + i - 2] - peak[i] + 1;
			if (res > ans) ans = res, l = i + 1;
		}

		cout << ans << ' ' << l << '\n';
	}
}