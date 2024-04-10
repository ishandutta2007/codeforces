#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int b[301];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n / 2; i++)
		{
			cout << b[i] << ' ';
			cout << b[n - 1 - i] << ' ';
		}

		if (n % 2) cout << b[n / 2] << ' ';
		cout << '\n';
	}
}