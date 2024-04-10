#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

pll a[200001];
ll psum[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].first;
			a[i].second = i;
		}

		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
			psum[i] = psum[i - 1] + a[i].first;

		vector <int> ans;
		for (int i = n; i > 0; i--)
		{
			ans.push_back(a[i].second);
			if (psum[i - 1] < a[i].first) break;
		}

		sort(ans.begin(), ans.end());

		cout << ans.size() << '\n';
		for (int x : ans) cout << x << ' ';
		cout << '\n';
	}
}