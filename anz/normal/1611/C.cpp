#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		if (a[0] == n || a[n - 1] == n)
		{
			for (int i = n - 1; i >= 0; i--) cout << a[i] << ' ';
			cout << '\n';
		}
		else cout << "-1\n";
	}
}