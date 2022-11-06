#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		string s; cin >> s;

		bool isp = true;
		for (int i = 0; i < n; i++) if (s[i] != s[n - 1 - i]) isp = false;

		if (k == 0 || isp) cout << "1\n";
		else cout << "2\n";
	}
}