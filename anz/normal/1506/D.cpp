#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
map <int, int> mp;
set <pii> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		mp.clear();
		st.clear();

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			mp[a]++;
		}

		for (auto it : mp)
			st.insert({ it.second, it.first });

		while (st.size() > 1)
		{
			auto a = *prev(st.end());
			auto b = *prev(prev(st.end()));

			st.erase(a);
			st.erase(b);

			if (--a.first) st.insert(a);
			if (--b.first) st.insert(b);
		}

		if (st.empty()) cout << "0\n";
		else cout << st.begin()->first << '\n';
	}
}