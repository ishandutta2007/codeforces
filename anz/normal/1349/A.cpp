#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 100001;

int n;
int a[N];

int segTree[N * 4];
void update(int ptr, int l, int r, int i, int val)
{
	if (l > i || r < i) return;
	if (l == r)
	{
		segTree[ptr] = val;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[ptr] = gcd(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		update(1, 0, n - 1, i, a[i]);
	}

	ll ans = 1;
	for (int i = 0; i < n; i++)
	{
		int tmp = a[i];
		update(1, 0, n - 1, i, 0);
		
		ll res = segTree[1];
		ans = ans * res / gcd(ans, res);

		update(1, 0, n - 1, i, tmp);
	}

	cout << ans;
}