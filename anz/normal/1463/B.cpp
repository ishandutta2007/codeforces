#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		ll sum[2] = { 0,0 };
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum[i % 2] += a[i];
		}

		for (int i = 0; i < n; i++)
		{
			if ((sum[0] < sum[1]) == (i % 2 == 0)) cout << "1 ";
			else cout << a[i] << ' ';
		}
		cout << '\n';
	}
}