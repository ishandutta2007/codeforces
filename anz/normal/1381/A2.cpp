#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> a >> b;

		int st = 0, ed = n - 1;
		bool inv = false;

		vector <int> ans;
		for (int i = n - 1; i >= 0; i--)
		{
			if (!inv && a[ed] == b[i] || inv && a[ed] != b[i])
			{
				if (inv) ed++;
				else ed--;
				continue;
			}

			if (a[st] != a[ed])
			{
				ans.push_back(1);
				a[st] = a[ed];
			}

			ans.push_back(i + 1);
			inv = !inv;
			swap(st, ed);

			if (inv) ed++;
			else ed--;
		}

		cout << ans.size();
		for (int it : ans) cout << ' ' << it;
		cout << '\n';
	}
}