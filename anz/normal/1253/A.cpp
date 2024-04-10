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

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[100001], b[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		bool ans = true;

		int hasChanged = 0;
		int curK = -1;

		for (int i = 0; i < n; i++)
		{
			if (a[i] == b[i])
			{
				if (hasChanged == 1)
				{
					hasChanged = 2;
				}
				continue;
			}

			if (hasChanged == 2)
			{
				ans = false;
				break;
			}
			else if (hasChanged == 1)
			{
				if (b[i] - a[i] != curK)
				{
					ans = false;
					break;
				}
			}
			else
			{
				if (b[i] - a[i] <= 0)
				{
					ans = false;
					break;
				}
				else
				{
					hasChanged = 1;
					curK = b[i] - a[i];
				}
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}