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
	ll n, T, a, b;
	cin >> n >> T >> a >> b;
	vector<pair<ll, ll>> s(n);
	ll tota = 0, totb = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].Y;
		if (s[i].Y == 0)
		{
			tota++;
		}
	}
	totb = n - tota;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].X;
	}
	if (T >= tota * a + totb * b)
	{
		cout << n << endl;
		return;
	}
	sort(s.begin(), s.end());
	ll cnta = 0;
	ll cntb = 0;
	ll ans = 0;
	for (int i = -1; i < n-1; )
	{
		if (i!=-1 and s[i].Y == 0)
		{
			cnta++;
		}
		else
		{
			if (i!=-1)
			cntb++;
		}
		i++;
		if (i != 0 and s[i].X == s[i - 1].X)
		{
			continue;
		}
		ll p = s[i].X - 1;
		if (p <= 0)
		{
			continue;
		}
		if (p < cnta*a+cntb*b)
		{
			continue;
		}
		ll tmp = cnta + cntb;
		p = p - cnta * a - cntb * b;
		ll kek = p / a;
		if (kek <= tota - cnta)
		{
			tmp += kek;
			if (ans < tmp)
			{
				ans = tmp;
			}
			continue;
		}
		tmp += tota - cnta;
		p -= (tota - cnta)*a;
		kek = p / b;
		if (kek > totb - cntb)
		{
			ans = n;
			continue;
		}
		tmp += kek;
		ans = max(ans, tmp);
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