#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
map <int, int> mp;
int a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		mp.clear();

		int ans = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mp[a[i]]++;
		}

		for (auto it : mp)
		{
			if (it.second > 1) continue;
			for (int i = 0; i < n; i++)
			{
				if (a[i] == it.first) ans = i + 1;
			}
			break;
		}

		cout << ans << '\n';
	}
}