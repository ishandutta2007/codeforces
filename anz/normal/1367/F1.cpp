#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];
vector <int> x;
vector <int> idx[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		x.clear();

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			x.push_back(a[i]);
			idx[i].clear();
		}
		idx[n].clear();

		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());

		for (int i = 0; i < n; i++)
		{
			int res = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
			a[i] = res;
			idx[res].push_back(i);
		}

		int ans = 987654321;

		int s = 0;
		int last = -1;
		int sum = 0;

		for (int i = 0; i < x.size(); i++)
		{
			if (idx[i].front() > last)
			{
				sum += idx[i].size();
				last = idx[i].back();

				continue;
			}

			int e = i - 1;

			if (s) sum += lower_bound(idx[s - 1].begin(), idx[s - 1].end(), idx[s].front())
				- idx[s - 1].begin();

			sum += idx[e + 1].size()
				- (lower_bound(idx[e + 1].begin(), idx[e + 1].end(), idx[e].back()) - idx[e + 1].begin());

			ans = min(ans, n - sum);

			s = i;
			sum = idx[i].size();
			last = idx[i].back();
		}

		int e = x.size() - 1;
		if (s) sum += lower_bound(idx[s - 1].begin(), idx[s - 1].end(), idx[s].front())
			- idx[s - 1].begin();

		sum += idx[e + 1].size()
			- (lower_bound(idx[e + 1].begin(), idx[e + 1].end(), idx[e].back()) - idx[e + 1].begin());

		ans = min(ans, n - sum);

		for (int i = 0; i < n; i++)
		{
			int res = lower_bound(idx[a[i]].begin(), idx[a[i]].end(), i) - idx[a[i]].begin() + 1;
			res += idx[a[i] + 1].size()
				- (lower_bound(idx[a[i] + 1].begin(), idx[a[i] + 1].end(), i) - idx[a[i] + 1].begin());

			ans = min(ans, n - res);
		}

		cout << ans << '\n';
	}
}