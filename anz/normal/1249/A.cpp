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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--)
	{
		int n; cin >> n;
		int a[101];
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);

		int last = -1;
		int ans = 0;
		int cnt = 0;
		while (cnt < n)
		{
			last = -1;
			for (int i = 0; i < n; i++)
			{
				if (a[i] == 0) continue;
				if (a[i] > last + 1)
				{
					last = a[i];
					a[i] = 0;
					
					cnt++;
				}
			}
			ans++;
		}
		cout << ans << "\n";
	}
}