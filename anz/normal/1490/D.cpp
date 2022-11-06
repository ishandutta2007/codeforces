#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[101];
int ans[101];

void solve(int l, int r, int d)
{
	if (l >= r) return;

	int mx = 0;
	int idx = -1;
	for (int i = l; i < r; i++)
	{
		if (a[i] > mx) mx = a[i], idx = i;
	}

	ans[idx] = d;
	solve(l, idx, d + 1);
	solve(idx + 1, r, d + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		solve(0, n, 0);

		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}