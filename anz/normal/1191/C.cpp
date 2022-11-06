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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

ll n, m, k;
ll special[100001];

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) cin >> special[i];

	ll ans = 0;

	ll removed = 0;
	int ptr = 0;
	while (ptr < m)
	{
		ll tmp = 0;
		ll curSpecial = special[ptr];
		ll curRoom = (curSpecial - removed-1) / k;
		while (true)
		{
			ll tSpecial = special[ptr];
			ll tRoom = (tSpecial - removed-1) / k;
			if (curRoom == tRoom) tmp++, ptr++;
			else break;
		}

		ans++;
		removed += tmp;
	}

	cout << ans;
}