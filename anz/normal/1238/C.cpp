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

ll h, n;
vector <ll> p;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--)
	{
		cin >> h >> n;
		p.resize(n);
		for (auto &i : p) cin >> i;
		p.push_back(0);

		int ans = 0;

		int isPlus = 0;
		for (int i = 0; i < n; i++)
		{
			int c = p[i] + isPlus;
			if (c <= 2) break;

			if (isPlus)
			{
				if (p[i + 1] == p[i] - 1)
				{
					isPlus = 0;
					continue;
				}

				ans++;
			}
			else
			{
				if (p[i + 1] != p[i] - 1)
				{
					isPlus = 1;
					continue;
				}

				if (p[i + 2] == p[i] - 2)
				{
					i++;
					continue;
				}

				i++;
				ans++;
				isPlus = 1;
			}
		}

		cout << ans << "\n";
	}
}