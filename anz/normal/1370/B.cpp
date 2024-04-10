#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> a[2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		a[0].clear(), a[1].clear();

		cin >> n;
		for (int i = 1; i <= n * 2; i++)
		{
			int x; cin >> x;
			a[x % 2].push_back(i);
		}

		int cnt = 0;
		for (int k = 0; k < 2; k++)
		{
			for (int i = 0; i < a[k].size() / 2 && cnt < n - 1; i++)
			{
				cout << a[k][i * 2] << ' ' << a[k][i * 2 + 1] << '\n';
				cnt++;
			}
		}
	}
}