//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <array>
#include <string>
#include <set>
#include <map>
#include <assert.h>
#include <unordered_map>
#include <queue>
#include <deque>

#define X first
#define Y second

using ll = long long;
using ld = long double;

using namespace std;


void solve()
{
	ll n, p, k;
	cin >> n >> p >> k;
	vector<ll> a(n+1);
	vector<vector<ll>> pref(k);
	for (int i = 0; i < k; i++)
	{
		pref[i].push_back(0);
	}
	a[0] = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i+1];
	}
	sort(a.begin(), a.end());
	for (int i = k; i <= n; i++)
	{
		int u = i % k;
		ll tmp = pref[u].back();
		pref[u].push_back(tmp + a[i]);
	}
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		if (p < 0)
		{
			break;
		}
		int l = 0;
		int r = pref[i].size();
		while (r - l > 1)
		{
			int m = (r + l) / 2;
			if (pref[i][m] <= p)
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}
		if (ans < i + (l) * k)
		{
			ans = i + (l) * k;
		}
		p -= a[i+1];
	}
	cout << ans << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}
}