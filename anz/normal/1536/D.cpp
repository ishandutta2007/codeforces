#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int b[200001];

deque <int> v;
map <int, int> idx;
set <int> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		v.clear();
		idx.clear();

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			v.push_back(b[i]);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			idx[v[i]] = i;
		}

		int l = 0;
		int r = v.size();

		bool ans = true;
		for (int i = 0; i < n; i++)
		{
			int ci = idx[b[i]];
			l = min(l, ci - i);
			r = max(r, ci + i + 1);
		}

		if (r - l > 2 * n - 1)
		{
			cout << "NO\n";
			continue;
		}

		st.clear();
		st.insert(b[0]);
		auto ptr = st.begin();

		for (int i = 1; i < n; i++)
		{
			if (*ptr == b[i]) continue;

			if (*ptr > b[i])
			{
				if (ptr == st.begin())
				{
					st.insert(b[i]);
					ptr = st.begin();
				}
				else
				{
					if (*prev(ptr) <= b[i])
					{
						st.insert(b[i]);
						ptr = st.find(b[i]);
					}
					else
					{
						ans = false;
						break;
					}
				}
			}
			else
			{
				if (next(ptr) == st.end())
				{
					st.insert(b[i]);
					ptr = prev(st.end());
				}
				else
				{
					if (*next(ptr) >= b[i])
					{
						st.insert(b[i]);
						ptr = st.find(b[i]);
					}
					else
					{
						ans = false;
						break;
					}
				}
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}