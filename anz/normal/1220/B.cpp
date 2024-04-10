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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n;
ll m[1001][1001];
vector <ll> dv;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		cin >> m[i][j];

	ll g = m[0][1];
	for (int i = 2; i < n; i++) g = gcd(g, m[0][i]);

	for (ll i = 1; i*i <= g; i++)
	{
		if (g%i == 0)
		{
			dv.push_back(i);
			if (i*i != g) dv.push_back(g / i);
		}
	}

	for (auto i : dv)
	{
		ll ans[1001];
		ans[0] = i;
		for (int j = 1; j < n; j++) ans[j] = m[0][j] / i;

		bool flag = true;
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (j == k) continue;
				if (m[j][k] != ans[j] * ans[k])
				{
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}

		if (flag)
		{
			for (int j = 0; j < n; j++) cout << ans[j] << ' ';
			return 0;
		}
	}
}