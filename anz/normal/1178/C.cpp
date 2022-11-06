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

string s;

const ll MOD = 998244353;

ll w, h;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> w >> h;

	ll ans = 4;
	for (int i = 0; i < w - 1; i++)
	{
		ans *= 2;
		ans %= MOD;
	}
	for (int i = 0; i < h - 1; i++)
	{
		ans *= 2;
		ans %= MOD;
	}

	cout << ans;
}