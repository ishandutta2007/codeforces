#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int b[200001];

set <int> st;
set <int> tmp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		st.clear();

		int last = 1;

		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			if (last < b[i])
			{
				for (int j = last; j < b[i]; j++) st.insert(j);
			}

			last = b[i] + 1;
		}

		while (last <= 2 * n)
		{
			st.insert(last);
			last++;
		}

		int mn = 0, mx = 0;

		tmp = st;
		for (int i = 0; i < n; i++)
		{
			auto it = tmp.lower_bound(b[i]);
			if (it != tmp.end())
			{
				mx++;
				tmp.erase(it);
			}
		}

		tmp = st;
		for (int i = n - 1; i >= 0; i--)
		{
			auto it = tmp.lower_bound(b[i]);
			if (it == tmp.begin()) mn++;
			else
			{
				--it;
				tmp.erase(it);
			}
		}

		cout << mx - mn + 1 << '\n';
	}
}