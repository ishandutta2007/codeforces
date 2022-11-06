#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		map <int, int> mp;
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			mp[a]++;
		}

		cout << n - mp.begin()->second << '\n';
	}
}