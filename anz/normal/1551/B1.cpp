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

	int T; cin >> T;
	while (T--)
	{
		string s; cin >> s;
		set <char> st[2];

		for (char c : s)
		{
			if (st[0].find(c) == st[0].end())
				st[0].insert(c);
			else if (st[1].find(c) == st[1].end())
				st[1].insert(c);
		}

		cout << (st[0].size() + st[1].size()) / 2 << '\n';
	}
}