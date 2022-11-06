#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int minx = 0, maxx = -0;
		int miny = 0, maxy = -0;

		int n; cin >> n;
		while (n--)
		{
			int x, y; cin >> x >> y;
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = min(miny, y);
			maxy = max(maxy, y);
		}

		cout << (maxx - minx + maxy - miny) * 2 << '\n';
	}
}