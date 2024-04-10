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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, m, k;
int block[101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) cin >> block[i];

		bool ans = true;
		ll rm = m;
		for (int i = 0; i < n - 1; i++)
		{
			rm += block[i];
			rm -= max(0, block[i + 1] - k);

			if (rm < 0)
			{
				ans = false;
				break;
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}