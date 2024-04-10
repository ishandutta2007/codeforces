#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
set <pair<pll, pll> > cor;
vector <pii> ans;

const ll MIN = -1000000000;
const ll MAX = 1000000000;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		ll x, y, z; cin >> x >> y >> z;
		cor.insert({ { x,y },{ z,i } });
	}

	while (!cor.empty())
	{
		auto c = *cor.begin();

		ll cx = c.first.first;
		ll cy = c.first.second;
		ll cz = c.second.first;
		int ci = c.second.second;
		cor.erase(cor.begin());

		auto n = *cor.begin();
		ll nx = n.first.first;
		ll ny = n.first.second;
		ll nz = n.second.first;
		int ni = n.second.second;

		if (cx == nx)
		{
			if (cy == ny)
			{
				ans.push_back({ ci,ni });
				cor.erase(cor.begin());
				continue;
			}

			auto lb = cor.lower_bound({ {nx,ny},{MIN,-1} });
			auto ub = cor.upper_bound({ {nx,ny},{MAX,-1} });

			ll minDir = (nx - cx)*(nx - cx) + (ny - cy)*(ny - cy) + (nz - cz)*(nz - cz);
			int res = ni;
			auto toErase = cor.begin();

			for (auto it = lb; it != ub; it++)
			{
				auto n = *it;
				ll nx = n.first.first;
				ll ny = n.first.second;
				ll nz = n.second.first;
				int ni = n.second.second;

				ll curDir = (nx - cx)*(nx - cx) + (ny - cy)*(ny - cy) + (nz - cz)*(nz - cz);
				if (minDir > curDir)
				{
					minDir = curDir;
					res = ni;
					toErase = it;
				}
			}

			ans.push_back({ ci,res });
			cor.erase(toErase);
		}
		else
		{
			auto lb = cor.lower_bound({ { nx,MIN },{ MIN,-1 } });
			auto ub = cor.upper_bound({ { nx,MAX },{ MAX,-1 } });

			ll minDir = (nx - cx)*(nx - cx) + (ny - cy)*(ny - cy) + (nz - cz)*(nz - cz);
			int res = ni;
			auto toErase = cor.begin();

			for (auto it = lb; it != ub; it++)
			{
				auto n = *it;
				ll nx = n.first.first;
				ll ny = n.first.second;
				ll nz = n.second.first;
				int ni = n.second.second;

				ll curDir = (nx - cx)*(nx - cx) + (ny - cy)*(ny - cy) + (nz - cz)*(nz - cz);
				if (minDir > curDir)
				{
					minDir = curDir;
					res = ni;
					toErase = it;
				}
			}

			ans.push_back({ ci,res });
			cor.erase(toErase);
		}
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << "\n";
}