#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int a[101];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				if (a[i] < 0) a[i] = -a[i];
			}
			else
			{
				if (a[i] > 0) a[i] = -a[i];
			}
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
}