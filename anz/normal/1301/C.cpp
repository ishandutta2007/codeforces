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

ll n, m;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;

		ll ans = n * (n + 1) / 2;
		
		ll div = (n - m) / (m + 1);
		ll rm = (n - m) % (m + 1);

		ans -= div * (div + 1) / 2 * (m + 1 - rm);
		ans -= (div + 1) * (div + 2) / 2 * rm;

		cout << ans << '\n';
	}
}