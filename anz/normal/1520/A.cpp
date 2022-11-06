#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;
int cache[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(cache, 0, sizeof cache);

		cin >> n >> s;
		s.erase(unique(s.begin(), s.end()), s.end());

		bool ans = true;
		for (char c : s)
		{
			int idx = c - 'A';
			if (cache[idx]) ans = false;
			cache[idx] = true;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}