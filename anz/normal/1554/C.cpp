#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> m; m++;
		vector <int> dn, dm;
		while (n)
		{
			dn.push_back(n % 2);
			n /= 2;
		}
		while (m)
		{
			dm.push_back(m % 2);
			m /= 2;
		}

		while (dm.size() < dn.size()) dm.push_back(0);

		int cm = 0;
		for (int i = 0; i < dn.size(); i++)
		{
			cm += dm[i] * (1 << i);
		}

		int ans = 0;
		for (int i = dn.size(); i < dm.size(); i++) ans += dm[i] * (1 << i);

		bool flag = false;
		for (int i = dn.size() - 1; i >= 0; i--)
		{
			if (dn[i] == 1 && dm[i] == 0)
			{
				flag = true;
				break;
			}

			ans += (dn[i] ^ dm[i]) * (1 << i);
		}

		cout << ans << '\n';
	}
}