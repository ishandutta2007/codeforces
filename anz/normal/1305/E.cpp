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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, m;
int main()
{
	cin >> n >> m;

	if (n == 1 && m == 0)
	{
		cout << 1;
		return 0;
	}

	if (n == 2 && m == 0)
	{
		cout << "1 2";
		return 0;
	}

	ll mx = 0;
	for (ll i = 3; i <= n; i++)
	{
		mx += (i - 3) / 2 + 1;
	}

	if (m > mx)
	{
		cout << -1;
		return 0;
	}

	ll bal = 0;
	vector <int> ans;
	ans.push_back(1);
	ans.push_back(2);

	for (ll i = 3; i <= n; i++)
	{
		ll tmp = (i - 3) / 2 + 1;
		if (bal + tmp >= m)
		{
			ans.push_back(i + (tmp + bal - m) * 2);
			break;
		}
		else
		{
			ans.push_back(i);
			bal += tmp;
		}
	}

	ll big = ans.back() + 1;
	ll tmp = 1000000000;
	while (ans.size() < n)
	{
		ans.push_back(tmp);
		tmp -= big;
	}

	sort(ans.begin(), ans.end());

	for (auto it : ans) cout << it << ' ';
}