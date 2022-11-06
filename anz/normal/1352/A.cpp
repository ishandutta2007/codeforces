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
		vector <int> ans;
		int n; cin >> n;
		if (n / 10000) ans.push_back(n / 10000 * 10000);
		n %= 10000;
		if (n / 1000) ans.push_back(n / 1000 * 1000);
		n %= 1000;
		if (n / 100) ans.push_back(n / 100 * 100);
		n %= 100;
		if (n / 10) ans.push_back(n / 10 * 10);
		n %= 10;
		if (n) ans.push_back(n);

		cout << ans.size() << '\n';
		for (int it : ans) cout << it << ' ';
		cout << '\n';
	}
}