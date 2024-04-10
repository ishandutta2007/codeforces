#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
ll a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << "1 1\n";
	cout << -a[0] << '\n';

	a[0] = 0;

	if (n >= 2)
	{
		cout << "2 " << n << '\n';
		for (int i = 1; i < n; i++)
		{
			cout << (n - 1) * a[i] << ' ';
			a[i] += (n - 1) * a[i];
		}
		cout << '\n';

		cout << "1 " << n << '\n';
		for (int i = 0; i < n; i++)
		{
			cout << -a[i] << ' ';
		}
	}
	else
	{
		cout << "1 1\n";
		cout << "0\n";
		cout << "1 1\n";
		cout << "0\n";
	}
}