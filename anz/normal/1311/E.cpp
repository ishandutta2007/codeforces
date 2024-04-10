#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

set <pii> depth;

int par[5001];
int child[5001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll n, d; cin >> n >> d;
		if (n >= 700 || d > n* (n - 1) / 2)
		{
			cout << "NO\n";
			continue;
		}

		depth.clear();
		for (int i = 0; i < 5001; i++) par[i] = -1, child[i] = 0;

		for (int i = 1; i <= n; i++)
		{
			depth.insert({ i, i });
			par[i] = i - 1;
			child[i - 1]++;
		}

		ll cd = n * (n - 1) / 2;
		while (cd != d)
		{
			auto cit = --depth.end();
			int cn = cit->second;
			int dd = cit->first;

			if (dd == 2) break;

			int pd = dd - 2;

			bool flag = false;
			while (pd)
			{
				auto it = depth.lower_bound({ pd, 0 });
				while (it != depth.end() && it->first == pd)
				{
					int nn = it->second;
					if (child[nn] == 2)
					{
						it++;
						continue;
					}

					flag = true;
					child[par[cn]]--;
					child[nn]++;
					par[cn] = nn;

					depth.erase(cit);
					depth.insert({--dd, cn});
					cit = depth.find({ dd, cn });

					cd--;
					break;
				}

				if (cd == d) break;

				pd--;
			}

			if (!flag) break;
		}

		if (cd == d)
		{
			cout << "YES\n";
			for (int i = 2; i <= n; i++) cout << par[i] << ' ';
			cout << '\n';
			continue;
		}

		cout << "NO\n";
	}
}