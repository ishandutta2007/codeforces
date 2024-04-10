#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int d[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		string s, t; cin >> s >> t;
		for (int i = 0; i < s.size(); i++)
			d[s[i] - 'a'] = i;

		int ans = 0;
		for (int i = 1; i < t.size(); i++)
			ans += abs(d[t[i] - 'a'] - d[t[i - 1] - 'a']);

		cout << ans << '\n';
	}
}