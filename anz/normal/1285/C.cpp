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

vector <ll> dv;
ll X;
ll ans;

void DFS(int s, ll cur)
{
	if (s >= dv.size()) return;
	ans = min(ans, max(cur, X / cur));

	DFS(s + 1, cur);
	DFS(s + 1, cur * dv[s]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll x; cin >> x;
	X = ans = x;
	for (ll i = 2; i * i <= x; i++)
	{
		ll res = 1;
		while (x % i == 0)
		{
			res *= i;
			x /= i;
		}

		if (res > 1) dv.push_back(res);
	}
	if (x > 1) dv.push_back(x);

	sort(dv.begin(), dv.end());

	DFS(0, 1);
	cout << ans << ' ' << X / ans;
}