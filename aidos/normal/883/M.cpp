#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"

inline int dist(int x1, int y1, int x2, int y2) {
	return abs(y2 - y1) + abs(x2 - x1);
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	int x1, x2, y1, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	if (x1 == x2) ++x1;
	if (y1 == y2) ++y1;
	int ans = 0;
	for (int sx = -1; sx <= 1; ++sx)
		for (int sy = -1; sy <= 1; ++sy) {
			if (abs(sx) + abs(sy) != 2) continue;
			int dx = x2 + sx;
			int dy = y2 + sy;
			ans = max(ans, dist(dx, dy, x1, y1) * 2);
		}
	cout << ans << endl;

	return 0;
}