#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;
vector <int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> s;
		v.clear();

		int cnt = 0;
		for (char c : s)
		{
			if (c == '0')
			{
				if (cnt) v.push_back(cnt);
				cnt = 0;
			}
			else cnt++;
		}

		v.push_back(cnt);

		sort(v.rbegin(), v.rend());

		int ans = 0;
		for (int i = 0; i < v.size(); i += 2) ans += v[i];
		cout << ans << '\n';
	}
}