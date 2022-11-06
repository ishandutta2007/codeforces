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
		deque <int> v;
		for (char c : s)
			v.push_back(c - 'a');

		bool ans = true;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (v.front() == i)
			{
				v.pop_front();
				continue;
			}

			if (v.back() == i)
			{
				v.pop_back();
				continue;
			}

			ans = false;
			break;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}