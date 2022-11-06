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
		int cnt[2] = { 0,0 };
		for (auto c : s)
			cnt[c - '0']++;

		if (cnt[0] == 0 || cnt[1] == 0) cout << s << '\n';
		else
		{
			for (int i = 0; i < s.size(); i++) cout << "01";
			cout << '\n';
		}
	}
}