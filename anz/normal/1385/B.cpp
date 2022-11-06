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
		set <int> st;
		vector <int> ans;

		int n; cin >> n;
		for (int i = 0; i < 2 * n; i++)
		{
			int a; cin >> a;
			if (st.find(a) == st.end()) ans.push_back(a);
			st.insert(a);
		}

		for (int it : ans) cout << it << ' ';
		cout << '\n';
	}
}