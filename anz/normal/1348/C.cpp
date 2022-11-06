#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int k, n;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cin >> s;

		map <char, int> mp;
		for (auto c : s) mp[c]++;

		int res = 0;
		set <char> st;
		for (auto it = mp.begin(); it != mp.end();)
		{
			char c = it->first;
			int v = it->second;

			st.insert(c);
			for (int i = 0; i < v; i++)
			{
				mp[c]--;
				if (++res == k) break;
			}

			it++;
			if (mp[c] == 0) mp.erase(c);

			if (res == k) break;
		}

		if (st.size() > 1)
		{
			cout << *prev(st.end()) << '\n';
			continue;
		}

		if (mp.size() <= 1)
		{
			cout << *st.begin();
			for (auto it : mp)
			{
				char c = it.first;
				int v = it.second;

				for (int i = 0; i < (v - 1) / k + 1; i++) cout << c;
			}
			cout << '\n';
			continue;
		}

		cout << *st.begin();
		for (auto it : mp)
		{
			char c = it.first;
			int v = it.second;

			for (int i = 0; i < v; i++) cout << c;
		}
		cout << '\n';
	}
}