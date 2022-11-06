#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
map <int, vector<int> > mp;
vector <pii> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		mp.clear();
		ans.clear();

		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			mp[a].push_back(i + 1);
		}

		if (mp.size() == 1)
		{
			cout << "NO\n";
			continue;
		}

		auto it = mp.begin();
		int root = it->second.front();

		int nr = -1;
		for (auto it = ++mp.begin(); it != mp.end(); it++)
		{
			for (int& v : it->second)
			{
				ans.push_back({ root, v });
				nr = v;
			}
		}

		for (int i = 1; i < it->second.size(); i++)
		{
			ans.push_back({ nr, it->second[i] });
		}

		cout << "YES\n";
		for (auto it : ans)
			cout << it.first << ' ' << it.second << '\n';
	}
}