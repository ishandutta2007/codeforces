#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int k, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;

		set <int> s;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			s.insert(x);
		}

		if (s.size() > k)
		{
			cout << "-1\n";
			continue;
		}

		cout << n * k << '\n';
		for (int i = 0; i < n; i++)
		{
			for (auto x : s) cout << x << ' ';
			for (int j = 0; j < k - s.size(); j++) cout << *s.begin() << ' ';
		}
		cout << '\n';
	}
}