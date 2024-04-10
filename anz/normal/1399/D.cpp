#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;
int ans[200001];

set <int> idx[2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> s;
		idx[0].clear();
		idx[1].clear();

		for (int i = 0; i < s.size(); i++)
		{
			idx[s[i] - '0'].insert(i);
		}

		int cnt = 0;
		while (!idx[0].empty() || !idx[1].empty())
		{
			cnt++;
			int start, ci;
			if (idx[0].empty()) start = 1;
			else if (idx[1].empty()) start = 0;
			else
			{
				if (*idx[0].begin() < *idx[1].begin()) start = 0;
				else start = 1;
			}

			if (start == 0) ci = *idx[0].begin();
			else ci = *idx[1].begin();

			auto it = idx[start].lower_bound(ci);
			while (true)
			{
				ans[*it] = cnt;
				idx[start].erase(it);

				start = 1 - start;
				it = idx[start].lower_bound(ci);
				
				if (it == idx[start].end()) break;
				ci = *it;
			}
		}

		cout << cnt << '\n';
		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}