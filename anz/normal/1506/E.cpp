#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int q[200001];
int ans_min[200001];
int ans_max[200001];

set <int> rm_min, rm_max;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		rm_min.clear(), rm_max.clear();

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			rm_min.insert(i);
			rm_max.insert(i);
		}

		for (int i = 1; i <= n; i++)
		{
			cin >> q[i];
			if (q[i] == q[i - 1])
			{
				int mn = *rm_min.begin();
				ans_min[i] = mn;
				rm_min.erase(mn);

				int mx = *prev(rm_max.lower_bound(q[i]));
				ans_max[i] = mx;
				rm_max.erase(mx);
			}
			else
			{
				ans_min[i] = ans_max[i] = q[i];
				rm_min.erase(q[i]);
				rm_max.erase(q[i]);
			}
		}

		for (int i = 1; i <= n; i++)
			cout << ans_min[i] << ' ';
		cout << '\n';
		for (int i = 1; i <= n; i++)
			cout << ans_max[i] << ' ';
		cout << '\n';
	}
}