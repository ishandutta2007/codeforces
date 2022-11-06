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
		string s; cin >> s;

		bool ans = true;
		if (s.size() % 2) ans = false;

		if (s[0] == ')' || s[s.size() - 1] == '(') ans = false;

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}