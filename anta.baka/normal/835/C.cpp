#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, q, c;
int p[11][100][100];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q >> c;
	c++;
	for(int i = 0; i < n; i++) {
		int x, y, s;
		cin >> x >> y >> s;
		--x; --y;
		for(int j = 0; j < c; j++) {
			p[j][x][y] += s;
			s = (s + 1) % c;
		}
	}
	for(int k = 0; k < c; k++)
		for(int i = 0; i < 100; i++)
			for(int j = 0; j < 100; j++)
				p[k][i][j] += (i ? p[k][i - 1][j] : 0) + (j ? p[k][i][j - 1] : 0) - (i && j ? p[k][i - 1][j - 1] : 0);
	for(int i = 0; i < q; i++) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		--x1; --y1; --x2; --y2;
		t %= c;
		cout << p[t][x2][y2] - (x1 ? p[t][x1 - 1][y2] : 0) - (y1 ? p[t][x2][y1 - 1] : 0) + (x1 && y1 ? p[t][x1 - 1][y1 - 1] : 0) << '\n';
	}
}