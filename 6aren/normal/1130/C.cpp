#include <bits/stdc++.h>

using namespace std;

int n, l, q, s, t;

string o;

int a[55][55], p[4000];

int dx[4] = {1, - 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int find(int u) {
	if (p[u] == u) return u; 
	return (p[u] = find(p[u]));
}


void hop(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) p[u] = v;
}

int calc(int a, int b) {
	return (a / 51 - b / 51) * (a / 51 - b / 51) + (a % 51 - b % 51) * (a % 51 - b % 51);
}

vector<int> from, to;

int main() {
	//freopen("in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cin >> l >> q >> s >> t;

	for (int i = 0 ; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			a[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> o;
		for (int j = 1; j <= n; j++) {
			a[i + 1][j] = (int) (o[j - 1] - '0');
		}
	}

	for (int i = 0; i < 4000; i++) {
		p[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 4; k++) {
				if (a[i][j] == 0 && a[i + dx[k]][j + dy[k]] == 0) {
					hop(i * 51 + j, (i + dx[k]) * 51 + j + dy[k]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = find(i * 51 + j);
		}
	}

	if (a[l][q] == a[s][t]) {
		return cout << 0, 0;
	}

	int mini = 1e9;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == a[s][t]) {
				from.push_back(i * 51 + j);
			}
			if (a[i][j] == a[l][q]) {
				to.push_back(i * 51 + j);
			}
		}
	}

	for (int i = 0; i < from.size(); i++) {
		for (int j = 0; j < to.size(); j++) {
			mini = min(calc(from[i], to[j]), mini);
		}
	}

	cout << mini;

	return 0;
}
//g++ online.cpp -o online.exe