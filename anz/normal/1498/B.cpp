#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, w;
ll a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> w;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		reverse(a, a + n);

		multiset <ll> st;
		st.insert(w);

		for (int i = 0; i < n; i++)
		{
			auto it = st.lower_bound(a[i]);
			if (it == st.end())
			{
				st.insert(w);
				it = st.lower_bound(a[i]);
			}

			ll x = *it;
			st.erase(it);
			st.insert(x - a[i]);
		}

		cout << st.size() << '\n';
	}
}