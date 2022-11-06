#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[2001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n * 2; i++) cin >> a[i];

		bool hasAns = false;
		int fv = -1;
		vector <pii> ans;

		sort(a, a + n * 2);
		for (int i = 0; i < n * 2 - 1; i++)
		{
			fv = a[n * 2 - 1] + a[n * 2 - 2 - i];

			bool isAns = true;
			
			ans.clear();
			multiset<int> st(a, a + 2 * n);

			int cv = fv;
			for (int i = 0; i < n; i++)
			{
				int b = *prev(st.end());
				st.erase(prev(st.end()));

				auto it = st.find(cv - b);
				if (it == st.end())
				{
					isAns = false;
					break;
				}

				int a = *it;
				st.erase(it);

				ans.push_back({ a,b });
				cv = b;
			}

			if (isAns)
			{
				hasAns = true;
				break;
			}
		}

		if (hasAns)
		{
			cout << "YES\n";
			cout << fv << '\n';
			for (auto it : ans)
				cout << it.first << ' ' << it.second << '\n';
		}
		else cout << "NO\n";
	}
}