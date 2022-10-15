#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define MAX 100000
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ld long double
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ld E = 1e-9;

int X[4] = { 1, 1, -1, -1 }, Y[4] = { -1, 1, 1, -1 };
int n, m;
int ar[2000][2000];

vector<pair<int, int> > v;

void bfs() {
	int l = -1;
	while (l < (int) v.size() - 1) {
		l++;
		if (ar[v[l].first][v[l].second] == 1)
			continue;
		ar[v[l].first][v[l].second] = 1;
		for (int z = 0; z < 4; z++) {
			int x = v[l].first + X[z], y = v[l].second + Y[z];
			if (x < 0 || y < 0 || x >= n || y >= m)
				continue;
			if (ar[x][y] + ar[x][v[l].second] + ar[v[l].first][y]
					+ ar[v[l].first][v[l].second] != 3)
				continue;
			if (ar[x][y] == 0)
				v.push_back(make_pair(x, y));
			if (ar[x][v[l].second] == 0)
				v.push_back(make_pair(x, v[l].second));
			if (ar[v[l].first][y] == 0)
				v.push_back(make_pair(v[l].first, y));
			if (ar[v[l].first][v[l].second] == 0)
				v.push_back(make_pair(v[l].first, v[l].second));
		}
	}
}

int main() {

	sync;

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++) {
		char c;
		cin >> c;
		ar[i][j] = c == '.';
	}

	for(int i = 1; i < n; i++)
	for(int j = 1; j < m; j++)
	if(ar[i][j] + ar[i - 1][j] + ar[i][j - 1] + ar[i - 1][j - 1] == 3) {
		if(ar[i][j] == 0)
		v.push_back(make_pair(i, j));
		if(ar[i - 1][j] == 0)
		v.push_back(make_pair(i - 1, j));
		if(ar[i][j - 1] == 0)
		v.push_back(make_pair(i, j - 1));
		if(ar[i - 1][j - 1] == 0)
		v.push_back(make_pair(i - 1, j - 1));
	}

	bfs();

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << (ar[i][j] ? '.' : '*');
		cout << endl;
	}

}