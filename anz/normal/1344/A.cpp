#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
ll a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		set <ll> st;
		for (ll i = 0; i < n; i++)
		{
			ll res = ((i + a[i]) % n + n) % n;
			st.insert(res);
		}
		if (st.size() == n) cout << "YES\n";
		else cout << "NO\n";
	}
}