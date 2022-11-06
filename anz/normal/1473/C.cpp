#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n - 1 - 2 * (n - k); i++)
			cout << i + 1 << ' ';
		for (int i = 0; i < n - k; i++)
			cout << k - i << ' ';
		cout << k - (n - k) << '\n';
	}
}