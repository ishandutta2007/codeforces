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
		string a, b; cin >> a >> b;

		int ans = 1e9;
		for (int i = 0; i < a.size(); i++) for (int j = 0; i + j <= a.size(); j++)
			for (int k = 0; k < b.size(); k++) for (int l = 0; k + l <= b.size(); l++)
			{
				string ta = a.substr(i, j);
				string tb = b.substr(k, l);
				
				if (ta == tb)
				{
					int res = a.size() + b.size() - j - l;
					ans = min(ans, res);
				}
			}

		cout << ans << "\n";
	}
}