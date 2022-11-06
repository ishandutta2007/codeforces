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

int n, q;
int a[200001];
int cur[200001];
map <pii, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], ans += a[i];

	cin >> q;
	while (q--)
	{
		int s, t, u; cin >> s >> t >> u;

		int pre = mp[{s, t}];
		if (pre)
		{
			if (cur[pre] <= a[pre]) ans++;
			cur[pre]--;
		}

		mp[{s, t}] = u;
		if (cur[u] < a[u]) ans--;
		cur[u]++;

		cout << ans << '\n';
	}
}