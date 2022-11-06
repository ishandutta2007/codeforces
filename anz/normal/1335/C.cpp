#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
map <int, int> mp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		mp.clear();

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			mp[a]++;
		}

		int mx = 0;
		for (auto it : mp) mx = max(mx, it.second);

		cout << max(min(mx, (int)mp.size() - 1),
			min(mx - 1, (int)mp.size())) << '\n';
	}
}