#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int k, n, m;
int a[301];
int b[301];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> k >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		bool hasAns = true;
		vector <int> ans;

		int ap = 0, bp = 0;
		while (ap < n || bp < m)
		{
			if (ap < n)
			{
				if (bp < m)
				{
					if (a[ap] == 0)
					{
						k++;
						ans.push_back(a[ap++]);
						continue;
					}

					if (b[bp] == 0)
					{
						k++;
						ans.push_back(b[bp++]);
						continue;
					}

					if (a[ap] < b[bp])
					{
						if (a[ap] > k)
						{
							hasAns = false;
							break;
						}

						ans.push_back(a[ap++]);
					}
					else
					{
						if (b[bp] > k)
						{
							hasAns = false;
							break;
						}

						ans.push_back(b[bp++]);
					}
				}
				else
				{
					if (a[ap] > k)
					{
						hasAns = false;
						break;
					}

					if (a[ap] == 0) k++;
					ans.push_back(a[ap++]);
				}
			}
			else
			{
				if (b[bp] > k)
				{
					hasAns = false;
					break;
				}
				if (b[bp] == 0) k++;
				ans.push_back(b[bp++]);
			}
		}

		if (!hasAns)
		{
			cout << "-1\n";
			continue;
		}

		for (int x : ans) cout << x << ' ';
		cout << '\n';
	}
}