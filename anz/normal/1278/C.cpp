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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector <int> left(n + 1), right(n + 1);
		map<int, int> mp;
		for (int i = 0; i < n; i++)
			cin >> left[n - i];
		for (int i = 0; i < n; i++)
			cin >> right[i + 1];

		for (int i = 1; i <= n; i++)
		{
			if (left[i] == 1) left[i] = left[i - 1] + 1;
			else left[i] = left[i - 1] - 1;

			if (right[i] == 1) right[i] = right[i - 1] + 1;
			else right[i] = right[i - 1] - 1;
		}

		for (int i = 0; i <= n; i++)
		{
			if (!mp.count(right[i]))
				mp[right[i]] = i;
		}

		int minAns = n * 2;
		int d = left[n] + right[n];
		for (int i = 0; i <= n; i++)
		{
			int curD = d - left[i];
			if (mp.count(curD))
			{
				minAns = min(minAns, i + mp[curD]);
			}
		}
		cout << minAns << '\n';
	}
}