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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		ll n, k; cin >> n >> k;
		if (k % 3 == 0)
		{
			ll tmp = k / 3;
			ll lp = 4 + (tmp - 1) * 3;

			if ((n%lp) % 3 == 0 && (n%lp) != lp - 1) cout << "Bob\n";
			else cout << "Alice\n";
		}
		else
			if (n % 3 == 0) cout << "Bob\n";
			else cout << "Alice\n";
	}
}