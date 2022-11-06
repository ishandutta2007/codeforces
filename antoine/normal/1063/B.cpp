#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
string a[2001];
int dist[2001][2001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int startX, startY, maxL, maxR;
	cin >> n >> m >> startX >> startY >> maxL >> maxR;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = " " + a[i];
	}

	memset(dist, 120, sizeof dist);

	typedef pair<int, pair<int, int>> Path;
	priority_queue<Path, vector<Path>, greater<Path>> pq;
	dist[startX][startY] = 0;
	pq.push( { 0, { startX, startY } });
	while (!pq.empty()) {
		const int i = pq.top().second.first;
		const int j = pq.top().second.second;
		const int d = pq.top().first;
		assert(a[i][j] == '.');
		pq.pop();
		if (d != dist[i][j])
			continue;

		for (int x = max(1, i - 1); x <= min(n, i + 1); ++x)
			for (int y = max(1, j - 1); y <= min(m, j + 1); ++y)
				if (abs(x - i) + abs(y - j) == 1 && a[x][y] == '.') {
					const int _d = d + abs(y - j);
					if (_d >= dist[x][y])
						continue;
					dist[x][y] = _d;
					pq.push( { _d, { x, y } });
				}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] != '.')
				continue;
			const int d = dist[i][j];
			if(d >= (n + 5) *(m+5) + 555) continue;
			// cerr << d << ' ';

			const int c = j - startY;
			assert((d + c) % 2 == 0);
			const int r = (d + c) / 2;
			const int l = d - r;
			assert(l >= 0 && r >= 0);
			ans += l <= maxL && r <= maxR;
		}
		// cerr << endl;
	}

	cout << ans << '\n';
	return 0;
}