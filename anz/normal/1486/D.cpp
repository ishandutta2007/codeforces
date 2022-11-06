#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
int a[200001];
int psum[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int l = 1, r = n + 1;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;

		bool flag = false;

		int cmin = 0;
		for (int i = 1; i <= k; i++)
		{
			if (a[i] >= m) psum[i] = psum[i - 1] + 1;
			else psum[i] = psum[i - 1] - 1;
		}

		if (psum[k] > 0) flag = true;
		for (int i = k + 1; i <= n; i++)
		{
			if (a[i] >= m) psum[i] = psum[i - 1] + 1;
			else psum[i] = psum[i - 1] - 1;
			cmin = min(cmin, psum[i - k]);

			if (psum[i] - cmin > 0) flag = true;
		}

		if (flag) l = m;
		else r = m;
	}

	cout << l;
}