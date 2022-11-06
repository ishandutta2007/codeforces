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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		set <int> s;
		for (int i = 1; i <= n; i++) s.insert(i);

		bool flag = true;
		int last = -1;
		vector <int> ans;
		for (int i = 0; i < n; i++)
		{
			int q; cin >> q;
			if (q > last)
			{
				last = q;
				s.erase(q);
				ans.push_back(q);
				continue;
			}

			if ((*s.begin()) >= q)
			{
				flag = false;
			}

			ans.push_back(*s.begin());
			s.erase(s.begin());
		}

		if (!flag) cout << "-1\n";
		else
		{
			for (int it : ans) cout << it << ' ';
			cout << '\n';
		}
	}
}