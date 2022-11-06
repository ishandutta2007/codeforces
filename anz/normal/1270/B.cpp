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

int n;
int a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		bool ans = false;
		int l = -1, r = -1;

		for (int i = 0; i < n - 1; i++)
		{
			int mn = min(a[i], a[i + 1]);
			int mx = max(a[i], a[i + 1]);
			if (mx - mn >= 2)
			{
				ans = true;
				l = i + 1, r = i + 2;
				break;
			}
		}

		if (!ans) cout << "NO\n";
		else cout << "YES\n" << l << ' ' << r << '\n';
	}
}