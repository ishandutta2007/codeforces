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

int m, n;
ll a[200001];

ll psum[200001];
ll ans[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++)
	{
		psum[i] = a[i];
		psum[i] += psum[i - 1];
	}

	for (int i = 1; i <= m; i++)
	{
		ans[i] = psum[i];
		for (int j = i + m; j <= n; j += m)
		{
			ans[j] = ans[j - m] + psum[j];
		}
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}