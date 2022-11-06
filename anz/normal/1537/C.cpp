#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int h[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> h[i];

		sort(h, h + n);

		int d = 2e9;
		int wh = -1;

		for (int i = 1; i < n; i++)
		{
			if (h[i] - h[i - 1] < d)
			{
				d = h[i] - h[i - 1];
				wh = i - 1;
			}
		}

		cout << h[wh] << ' ';
		for (int i = 2; i < n; i++)
		{
			cout << h[(wh + i) % n] << ' ';
		}

		cout << h[wh + 1] << '\n';
	}
}