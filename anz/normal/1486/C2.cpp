#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int query(int l, int r)
{
	if (l >= r) return 0;
	cout << "? " << l << ' ' << r << endl;
	int res; cin >> res;
	return res;
}

int main()
{
	cin >> n;

	int c = query(1, n);

	int l = 0, r = n;

	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		int res = query(max(1, c - m), min(n, c + m));

		if (res == c) r = m;
		else l = m;
	}

	if (query(max(1, c - r), c) == c) cout << "! " << max(1, c - r) << endl;
	else cout << "! " << min(n, c + r) << endl;
}