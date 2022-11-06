#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> ls[100001];
bool mat1[100001], mat2[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			ls[i].clear();
			mat1[i] = mat2[i] = 0;
			int k; cin >> k;
			while (k--)
			{
				int p; cin >> p;
				ls[i].push_back(p);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (auto p : ls[i])
			{
				if (mat2[p] == 0)
				{
					mat1[i] = 1;
					mat2[p] = 1;
					break;
				}
			}
		}

		int notMatched = 0;
		for (int i = 1; i <= n; i++)
		{
			if (mat2[i] == 0)
			{
				notMatched = i;
				break;
			}
		}

		if (notMatched == 0)
		{
			cout << "OPTIMAL\n";
			continue;
		}

		cout << "IMPROVE\n";
		for (int i = 1; i <= n; i++)
		{
			if (mat1[i] == 0)
			{
				cout << i << ' ' << notMatched << '\n';
				break;
			}
		}
	}
}