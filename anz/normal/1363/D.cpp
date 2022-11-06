#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
vector <vector <int> > s;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		s.clear();
		s.resize(k);

		for (int i = 0; i < k; i++)
		{
			int sz; cin >> sz;
			s[i].resize(sz);
			for (int j = 0; j < sz; j++) cin >> s[i][j];
		}

		cout << "? " << n;
		for (int i = 1; i <= n; i++) cout << " " << i;
		cout << endl;

		int mx; cin >> mx;
		
		int l = 0, r = k - 1;

		while (l < r)
		{
			int m = (l + r) / 2;

			vector <int> tmp;
			for (int i = l; i <= m; i++)
			{
				for (auto x : s[i]) tmp.push_back(x);
			}

			cout << "? " << tmp.size();
			for (auto x : tmp) cout << " " << x;
			cout << endl;

			int res; cin >> res;

			if (res == mx) r = m;
			else l = m + 1;
		}

		bool isExist[1001] = { 0, };
		for (auto x : s[l]) isExist[x] = 1;

		cout << "? " << n - s[l].size();
		for (int i = 1; i <= n; i++) if (!isExist[i]) cout << " " << i;
		cout << endl;

		int res; cin >> res;

		cout << "!";
		for (int i = 0; i < k; i++)
		{
			cout << " ";
			if (i == l) cout << res;
			else cout << mx;
		}
		cout << endl;

		string isOk; cin >> isOk;

		if (isOk != "Correct") return 0;
	}
}