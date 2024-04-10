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

int n, m;
int a[105];
set <int> p;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];

		p.clear();
		for (int i = 0; i < m; i++)
		{
			int x; cin >> x;
			p.insert(x);
		}

		vector <int> stk;
		int curMin = a[1];
		int curMax = a[1];
		for (int i = 1; i <= n; i++)
		{
			if (p.find(i) != p.end())
			{
				curMin = min(curMin, a[i + 1]);
				curMax = max(curMax, a[i + 1]);
			}
			else
			{
				stk.push_back(curMin);
				stk.push_back(curMax);
				curMin = a[i + 1];
				curMax = a[i + 1];
			}
		}

		bool ans = true;
		for (int i = 0; i < stk.size() - 1; i++)
		{
			if (stk[i] > stk[i + 1])
			{
				ans = false;
				break;
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}