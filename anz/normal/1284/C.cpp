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

ll n, m;
ll fac[250001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	fac[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		fac[i] = fac[i - 1] * i;
		fac[i] %= m;
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += (n + 1 - i)* fac[i] % m* fac[n + 1 - i] % m;
		ans %= m;
	}

	cout << ans;
}