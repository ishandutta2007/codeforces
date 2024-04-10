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
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, sx, sy;
pii ans[4] = { {0,0},{0,1},{0,2},{0,3} }; // left right down up

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> sx >> sy;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		if (x < sx) ans[0].first++;
		if (x > sx) ans[1].first++;
		if (y < sy) ans[2].first++;
		if (y > sy) ans[3].first++;
	}

	sort(ans, ans + 4);
	cout << ans[3].first << '\n';
	switch (ans[3].second)
	{
	case 0:
		cout << sx - 1 << ' ' <<  sy;
		break;
	case 1:
		cout << sx + 1 << ' ' << sy;
		break;
	case 2:
		cout << sx << ' ' << sy - 1;
		break;
	case 3:
		cout << sx << ' ' << sy + 1;
		break;
	}
}