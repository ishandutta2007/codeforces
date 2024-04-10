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
 
vector <ll> dv[30001];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	for (int i = 1; i <= 30000; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				dv[i].push_back(j);
				if (j * j != i) dv[i].push_back(i / j);
			}
		}
		sort(dv[i].begin(), dv[i].end());
	}
 
	int t; cin >> t;
	while (t--)
	{
		ll a, b, c; cin >> a >> b >> c;
 
		ll ans = 987654321987654321;
		ll ra, rb, rc;
		for (ll cb = 1; cb <= 30000; cb++)
		{
			ll trb = b > cb ? b - cb : cb - b;
 
			int ia = lower_bound(dv[cb].begin(), dv[cb].end(), a) - dv[cb].begin();
			if (ia == dv[cb].size()) ia--;
 
			ll ca = dv[cb][ia];
			ll tra = dv[cb][ia] - a;
			if (tra < 0) tra = -tra;
			if (ia)
			{
				if (tra > a - dv[cb][ia - 1])
				{
					tra = a - dv[cb][ia - 1];
					ca = dv[cb][ia - 1];
				}
			}
 
			ll cc = -1;
			ll cc1 = c / cb * cb;
			ll cc2 = cc1 + cb;
			ll trc = -1;
			if (c - cc1 < cc2 - c)
			{
				trc = c - cc1;
				cc = cc1;
			}
			else
			{
				trc = cc2 - c;
				cc = cc2;
			}
 
			ll res = tra + trb + trc;
			if (res < ans)
			{
				ans = res;
				ra = ca, rb = cb, rc = cc;
			}
		}
 
		cout << ans << '\n';
		cout << ra << ' ' << rb << ' ' << rc << '\n';
	}
}