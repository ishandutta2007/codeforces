#include <bits/stdc++.h>
#include <random>
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

	cout.precision(6);
	cout << fixed;

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a, a + n);
		ll sum = 0;
		for (int i = 0; i < n - 1; i++) sum += a[i];

		cout << (double)sum / (n - 1) + a[n - 1] << '\n';
	}
}