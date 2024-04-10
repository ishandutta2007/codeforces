#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[50];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n * 2; i++) cin >> a[i];
		sort(a, a + n * 2);
		for (int i = 0; i < n; i++) cout << a[i] << ' ' << a[2 * n - 1 - i] << ' ';
		cout << '\n';
	}
}