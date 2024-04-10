#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];
bool isValid[200001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];

		vector <int> ans;
		set <int> s;
		for (int i = 1; i < n; i++)
		{
			s.insert(a[i]);
			if (s.size() == i && *--s.end() == i) isValid[i] = 1;
			else isValid[i] = 0;
		}

		s.clear();
		for (int i = 1; i < n; i++)
		{
			s.insert(a[n + 1 - i]);
			if (s.size() == i && *--s.end() == i)
			{
				if (isValid[n - i]) ans.push_back(n - i);
			}
		}

		cout << ans.size() << '\n';
		for (auto it : ans) cout << it << ' ' << n - it << '\n';
	}
}