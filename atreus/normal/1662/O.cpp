#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 77;

bool visited[44][722];
vector<int> cir[maxn], str[maxn];
char type[maxn];
int a[maxn], b[maxn], c[maxn];
vector<pair<int,int>> g[42][720];

bool dfs(int r, int theta) {
	if (visited[r][theta])
		return false;
	visited[r][theta] = 1;
	if (r == 41)
		return true;
	for (auto [r2, theta2] : g[r][theta])
		if (dfs(r2, theta2))
			return true;
	return false;
}

void add_edge(int r1, int theta1, int r2, int theta2) {
	g[r1][theta1].push_back({r2, theta2});
	g[r2][theta2].push_back({r1, theta1});
}

void solve() { 
	memset(visited, 0, sizeof visited);
	for (int r = 1; r <= 41; r += 2)
		for (int theta = 1; theta <= 719; theta += 2)
			g[r][theta].clear();
	for (int i = 0; i <= 720; i++)
		cir[i].clear(), str[i].clear();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> type[i] >> a[i] >> b[i] >> c[i];
		a[i] *= 2, b[i] *= 2, c[i] *= 2;
		if (type[i] == 'S')
			str[c[i]].push_back(i);
		else
			cir[a[i]].push_back(i);
	}
	for (int r = 1; r <= 39; r += 2) {
		for (int theta = 1; theta <= 719; theta += 2) {
			bool canRotate = true;
			for (int i : str[(theta + 1) % 720]) {
				if (a[i] < r and r < b[i]) {
					canRotate = false;
					break;
				}
			}
			if (canRotate)
				add_edge(r, theta, r, (theta + 2) % 720);

			bool canStraight = true;
			for (int i : cir[r + 1]) {
				if ((b[i] <= c[i] and b[i] <= theta and theta <= c[i]) or 
					(b[i] > c[i] and (theta <= c[i] or theta >= b[i]))) {
					canStraight = false;
					break;
				}
			}
			if (canStraight)
				add_edge(r, theta, r + 2, theta);
		}
	}
	for (int theta = 1; theta <= 719; theta += 2)
		if (dfs(1, theta)) {
			cout << "YES\n";
			return;
		}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
}