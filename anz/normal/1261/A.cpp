#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
string s;
vector <pii> ans;
set <int> open, close;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		ans.clear();
		open.clear(), close.clear();
		cin >> n >> k;
		cin >> s;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '(') open.insert(i);
			else close.insert(i);
		}

		int i = 0;
		for (; i < k * 2 - 2; i += 2)
		{
			if (s[i] != '(')
			{
				auto it = open.lower_bound(i);

				int l = i, r = *it;
				ans.push_back({ l,r });
				while (l < r)
				{
					bool lOpen = (s[l] == '(');
					bool rOpen = (s[r] == '(');

					if (lOpen != rOpen)
					{
						if (lOpen)
						{
							open.erase(l);
							close.erase(r);
							open.insert(r);
							close.insert(l);
						}
						else
						{
							open.erase(r);
							close.erase(l);
							open.insert(l);
							close.insert(r);
						}
					}

					swap(s[l], s[r]);
					l++;
					r--;
				}
			}
			if (s[i + 1] != ')')
			{
				auto it = close.lower_bound(i);

				int l = i + 1, r = *it;
				ans.push_back({ l,r });
				while (l < r)
				{
					bool lOpen = (s[l] == '(');
					bool rOpen = (s[r] == '(');

					if (lOpen != rOpen)
					{
						if (lOpen)
						{
							open.erase(l);
							close.erase(r);
							open.insert(r);
							close.insert(l);
						}
						else
						{
							open.erase(r);
							close.erase(l);
							open.insert(l);
							close.insert(r);
						}
					}

					swap(s[l], s[r]);
					l++;
					r--;
				}
			}
		}

		int li = i, ri = n - 1;
		while (li < ri)
		{
			if (s[li] == '(')
			{
				li++;
				ri--;
				continue;
			}

			auto it = open.lower_bound(li);

			int l = li, r = *it;
			ans.push_back({ l,r });
			while (l < r)
			{
				bool lOpen = (s[l] == '(');
				bool rOpen = (s[r] == '(');

				if (lOpen != rOpen)
				{
					if (lOpen)
					{
						open.erase(l);
						close.erase(r);
						open.insert(r);
						close.insert(l);
					}
					else
					{
						open.erase(r);
						close.erase(l);
						open.insert(l);
						close.insert(r);
					}
				}

				swap(s[l], s[r]);
				l++;
				r--;
			}

			li++;
			ri--;
		}
		cout << ans.size() << '\n';
		for (auto it : ans)
			cout << it.first + 1 << ' ' << it.second + 1 << '\n';
		//cout << s << '\n';
	}
}